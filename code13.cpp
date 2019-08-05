//Fibonacci数列是这样定义的： 
//F[0] = 0 F[1] = 1 for each i ≥ 2: F[i] = F[i-1] + F[i-2] 
//因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。
//给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，
//现在给你一个数N求最少需要多少步可以变为Fibonacci数。 
//输入描述： 输入为一个正整数N(1 ≤ N ≤ 1,000,000)
//输出描述： 输出一个最小的步数变为Fibonacci数" 
//示例1: 输入15输出2"


/*方法一
#include <iostream> 
using namespace std; 
int main()
{ 
    int N, f, l = 0,r = 0,f0 = 0,f1 = 1; 
    cin >> N; 
    while(1)
    {
        f = f0 + f1; 
        f0 = f1; 
        f1 = f; 
        //找到比N小且距离N最近的数，求出距离 
        if(f < N) 
            l = N-f;

        else 
        { 
            //找到比N大且距离N最近的数，求出距离 
            r = f - N; 
            break; 
        } 
    } 
    //取最小距离 
    cout << min(l,r) << endl; 
    return 0; 
}
*/





#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;


int Fib(int n)
{
    if (n == 0)
    {
        return 0;

    }
    else if (n == 1)
    {
        return 1;

    }
    else
    {
        return Fib(n - 1) + Fib(n - 2);

    }

}

int main()
{
    int N;
    cin >> N;
    int i = 0;
    int cur = 0;
    for (; i < 100000; i++)
    {
        if (Fib(i) > N)
        {
            cur = i;
            break;

        }

    }
    int A = abs(Fib(cur) - N);//由于Fiber(cur) > N,求出cur处与N的距离
    int B = abs(Fib(cur - 1) - N);//求出cur-1处与N的距离
    cout << (A < B ? A : B);
    return 0;

}
