<?hh
/**
 * 对外暴露函数，用c实现。
 * Native标识告诉编译器，不要试图找一块php代码编译实现。
 * 编译器要去找c++运行时输出的example_sum符号。
 */
<<__Native>>
function example_sum(int $a, int $b): int;

// 对外暴露函数，直接用php实现
function example_plus(int $a, int $b) {
    return $a + $b;
}