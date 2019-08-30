//所谓因子分解，就是把给定的正整数a，分解成若干个素数的乘积，即 a = a1 × a2 × a3 × ... ×an,并且 1 < a1 ≤ a2 ≤ a3  <= an。
//其中a1、a2、...、an均为素数。 先给出一个整数a，请输出分解后的因子。
//输入描述： 输入包含多组数据，每组数据包含一个正整数a（2≤a≤1000000）。
//输出描述： 对应每组数据，以“a = a1 * a2 * a3...”的形式输出因式分解后的结果。
//示例1:
//输入 
//10
//18
//输出
//10 = 2 * 5
//18 = 2 * 3 * 3


//【解题思路】：
//看到短除法后，我们很清楚的知道，要想求出它的每一个质因数，我们需要用质数去试除。90能被2整除，那就拿
//商继续除以2，除不尽就换3，一直到除到质数为止。基础代码框架类似判断质数，只是被判断的数字在过程中不断
//被除，最终循环结束的时候，那个被处理过的数字，就是最后一个质因数。以下代码注释以90为例。


#include<cstdio>
#include<cmath> 
#include<iostream>
int main() 
{
    unsigned int n;
    while(std::cin >> n)
    {
        printf("%d =", n);
        //输出90 = 
        for(unsigned i = 2; i <= std::sqrt(n);i++)
        {
            while(n % i == 0 && n != i) //反复除同一个数，直到除不尽，排除刚好是该数的n次方的情况
            {
                printf(" %u *", i); //第一次打印 2 *,第二次打印两个 3 *
                n /= i; //能整除就修改n的值 
            }
        }
        printf(" %d\n",n); //跳出后，n已经是处理过的一个质数，就是最后一个质因数：5 
    }
    return 0;
}