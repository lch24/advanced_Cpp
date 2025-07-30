# C++ 进阶知识

## 从源代码到可执行文件

### 一个 C++ 程序究竟是怎么跑起来的

在我们刚开始学习 C++ 的时候，我们运行程序的方法往往是使用 IDE，如 Visual Studio、CLion 等。IDE 会帮助我们完成编译、链接等步骤，最终生成可执行文件。我们只需要点击运行按钮，即可在 IDE 中看到程序的输出。

在本节课程中，我们将学习如何手动编译 C++ 程序，了解编译、链接等步骤的具体内容。

### 过程总览

![流程图](./assets/flowChart.png)

### 编译工具

针对不同的应用场景和平台，各大厂家设计了不同的C++编译工具

- MSVC（Microsoft Visual C++）：这是微软开发的一款 C++ 开发工具， Visual Studio 中就内置了 MSVC

- GCC（GNU Compiler Collection）：GCC 是由 GNU 开发的一套编译工具，支持多种语言。在本节课程中我们使用的编译工具就是 GCC（针对 C 的前端程序为 gcc，针对 C++ 的前端程序为 g++）

在本节课程中，我们使用 wsl 作为运行环境，当然，Windows 的环境也是可以的，你可以通过一下的代码完成 gcc 的安装

Linux：
~~~bash
sudo apt update
sudo apt install build-essential
~~~

Windows:
~~~bash
//请以管理员身份运行 powershell
Set-ExecutionPolicy RemoteSigned -scope CurrentUser
irm get.scoop.sh | iex

scoop bucket add main
scoop bucket add extras

scoop install gcc
~~~

当然，在 Windows 环境中你也可以直接到 [mingw](https://www.mingw-w64.org/downloads/) 的官网进行下载，并将 bin 目录添加到环境变量中。

### 预处理(Preprocessing)

```bash
g++ -E main.cpp -o main.i
```
作用：

- 处理 #include, #define, #ifdef 等预处理命令。
- 替换宏，展开头文件。

输出：.i 文件（纯C++代码，无预处理指令）

示例：../example/simplestCase

### 编译(Compiling)

~~~bash
g++ -S main.i -o main.s
~~~

这一步是编译原理课的重要内容，在这里只进行一些简单的介绍。，

编译的五大步骤：

- 词法分析
- 语法分析
- 语义分析与中间代码生成
- 优化
- 目标代码生成

#### 词法分析

在这一步中，词法分析器（Lexer）读取源代码，将其分解为一系列的标记（token）或词法分析单元（lexeme）。这些是编程语言中的基本元素，如关键字，标识符，字面量等。

~~~
int a = 3 + 5; -> [int] [a] [=] [3] [+] [5] [;]
~~~

#### 语法分析

语法分析器使用由词法分析器生成的各个词法单元来创建树形的中间表示。该中间表示给出了词法分析产生的词法单元流的语法结构。一个比较常见的表示方法是语法树(syntax tree)，树中的每一个内部节点表示一个运算，而子节点表示该运算的分量。

对于下面的代码：

~~~C++
damage=1.5*strength-defence
~~~

一颗比较符合直觉的语法分析树长成这样：

![正确的语法分析树](./assets/syntaxTree1.png)

但是也有可能长成这样：

![不正确的语法分析树](./assets/tree2.png)

这就是在编译中遇到的二义性问题。

对于另外一组代码：

~~~C++
if(a>1)
    if(a==2)
        std::cout<<"something1";
    else
        std::cout<<"something2";
~~~

同样地，编译器也并不知道 else 应该和哪个 if 配对。

为了解决二义性的问题，我们引入上下文无关文法这个概念，并通过合理地设计这个文法，消除由算符优先级和 if-else 悬挂所引起的文法二义性。

##### 上下文无关文法：

一个上下文无关文法是一个四元组，$ G= \{V,\sum,R,S\} $，其中 $V$ 是非终止符的集合， $\sum$ 是终止符的集合，$R$ 是产生式规则的集合，$S$ 是开始符号。

一个简单的例子：
$V=\{E\}$
$\sum=\{a,b\}$
$S \to E, E \to aEb | \epsilon$

消除由运算符优先级引起的文法二义性
~~~
<expr>   ::= <expr> "+" <term>
          | <expr> "-" <term>
          | <term>

<term>   ::= <term> "*" <factor>
          | <term> "/" <factor>
          | <factor>

<factor> ::= "(" <expr> ")"
          | number
          | identifier
~~~

消除由 if-else 悬挂引起的文法二义性

~~~
<stmt>           ::= <matched_stmt> | <unmatched_stmt>

<matched_stmt>   ::= "if" "(" <expr> ")" <matched_stmt> "else" <matched_stmt>
                  | <other_stmt>

<unmatched_stmt> ::= "if" "(" <expr> ")" <stmt>
                  | "if" "(" <expr> ")" <matched_stmt> "else" <unmatched_stmt>
~~~



### 汇编

### 链接

### 管理大型项目的构建：Makefile 与 Cmake