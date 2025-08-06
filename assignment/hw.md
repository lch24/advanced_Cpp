# 作业

## 1. 消去上下文无关文法的二义性

定义 %% 为距离运算(a %% b=|a-b|)，根据讲义中的无二义上下文无关文法，尝试给出 %% 与 * / 同优先级的上下文无关文法，以及 %% 是最高优先级的上下文无关文法。

## 2.CMake 实现构建模式切换以及跨平台编译提示

你需要实现两个功能：
- 在构建项目的时候通过命令行参数实现 debug 模式和 release 模式。debug 模式需要打印 src/analyze.cpp 中的调试信息，release 模式则不打印信息。hint：考虑通过 option 自定义命令行参数。
- 在构建过程中打印正在进行编译的环境是 Win 还是 Linux。

chusi/CMakelists.txt 为你提供了一个简单的框架，你可以在此之上补全两个功能点

要测试你的 CMakelists.txt 是否满足要求，你可以运行如下的指令：

~~~bash
//在 assignment 目录下
cmake -S yourFolderName -B build
cmake --build build
./build/bin/run
~~~

## 作业提交规范

- fork 项目仓库后创建自己的分支。
- 在该目录下创建能识别自己身份的文件夹，例如 ./chusi，并在这个文件夹中完成作业。
- 你的文件夹中应该有两项内容：第一问的 ans.txt 或 ans.md 文件以及第二问的 CMakelists.txt 文件。
- 不要修改 hw_proj 中的内容。
- 提交前注意要删除 build/ 以及其它编译过程中产生的文件。
- 向项目仓库的 assignment 分支提交 pull request.