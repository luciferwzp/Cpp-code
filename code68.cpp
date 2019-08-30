//一只成熟的兔子每天能产下一胎兔子。
//每只小兔子的成熟期是一天。 某人领养了一只小兔子，请问第N天以 后，他将会得到多少只兔子。
//输入描述： 测试数据包括多组，每组一行，为整数n(1≤n≤90)。
//输出描述： 对应输出第n天有几只兔子(假设没有兔子死亡现象)。 
//示例1:
//输入
//1
//2
//输出
//1
//2


//【解题思路】：
//本题的兔子第二天就开始下小兔了，所以这个是从第二项开始的斐波那契数列。前90组的数据恰好还在
//long long的范围内，所以不需要高精度，直接long long求解。


#include<iostream> 
#include<cstdio>
int main() 
{
    long long n[91] = { 1, 2  }; 
    for(int i = 2; i <= 90; i++)
    {
        n[i] = n[i - 1] + n[i - 2];  
    }
    int d; 
    while(std::cin >> d)
    {
        printf("%lld\n", n[d - 1]); 
    }
}