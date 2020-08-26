#include <iostream>

int g_n = 10;
const int g_n2 = 0;

void test1()
{
    const int i = 10;
    const int i1 = i;
    constexpr int j = 10;
    constexpr int j1 = j;   // 正确，因为编译期 j 的值已知
    int input;
    std::cin >> input;
    const int i2 = input;   // 正确
#ifdef NOTINIT
    constexpr int j2 = input;   // 无法编译，因为编译期 input 的值未知
#endif
}

// 要求返回的值是编译期常量
constexpr int func(int n) noexcept
{
    //return g_n; // 无法编译，因为 g_n 不是编译期常量
    
    // 正确，g_n2 和 n 都是编译期常量，虽然函数本身
    // 没有将 n 声明为 constexpr int，但是要求调用方传入的一定是 constexpr
    return g_n2 + n;
}

void test2()
{
    const int n1 = 10;
    constexpr int rlt1 = func(n1);  // 正确，因为 n1 是编译期常量
    int input;
    std::cin >> input;
    std::cin >> g_n;
    //constexpr int rlt2 = func(input);   // 无法编译，因为 input 不是编译期常量
}

int main()
{
    // test1();
    return 0;
}
