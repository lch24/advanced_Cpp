#pragma once

// 模板递归，制造编译期计算压力
template<int N>
struct Delay {
    static constexpr int value = Delay<N - 1>::value + 1;
};

template<>
struct Delay<0> {
    static constexpr int value = 0;
};
