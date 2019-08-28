//NowCoder开了一家早餐店，这家店的客人都有个奇怪的癖好：他们只要来这家店吃过一次早餐，就会每天 都过来；
//并且，所有人在这家店吃了两天早餐后，接下来每天都会带一位新朋友一起来品尝。 
//于是，这家店的客人从最初一个人发展成浩浩荡荡成百上千人：1、1、2、3、5……
//现在，NowCoder想请你帮忙统计一下，某一段时间范围那他总共卖出多少份早餐（假设每位客人只吃一份 早餐）。


//老样子，先准备好斐波那契的数组，然后遍历那一段数组，求出他们的和即可。而第80项斐波那契数列是一个17位数，
//所以需要用long long来解决问题。
//然而这个题还有另一个更有意思的思路。斐波那契数列的的前n项和其实是有一个很有意思的公式，
//公式推导在这里https://blog.csdn.net/ftx456789/article/details/82348742，根据文章我们能知道，斐波那契数列的前n项和，
//就是第n+2项的值减1，例如前10项的和143，就是第12项的144 - 1的结果。所以，我们如果我们要第n项到第m项的和，
//那么只要求出前m项的和，减去前n - 1项的和，就能得到结果了。
//例如要求第3项到第5项的和，我们就只需要用前5项的和减去前2项的和，而公式中的减一在这个过程中抵消掉了，
//也就是结果直接就是第7项的值减去第4项的值，这样我们在操作的时候就更简单了。
//就数值而言，第7项是13，第4项是3，差值是10，而2+3+5也是10，结果是正确的。


#include<iostream>
#define MAX 83 //如果用公式计算，需要接下来两项的值 
void solve(long long num[])
{
    for(int i = 2; i < MAX; i++)
    {
        num[i] = num[i - 1] + num[i - 2];
    }
}

long long sum_traversal(long long num[], int from, int to) //解法1：用遍历求和求解 
{
    long long ans = 0;
    for(int i = from - 1; i < to; i++) //让数组下标从from - 1遍历到to - 1
    {
        ans += num[i];
    }
    return ans;
}

long long sum_formula(long long num[], int from, int to) //解法2：用公式求解 
{
    return num[to + 1] - num[from]; //第to + 2项的下标是to + 1，第from + 2 - 1项的下 标是from 
}

int main() 
{
    int from, to;
    long long num[MAX] = {1, 1}; //提前计算Fibonacci数列 
    solve(num);
    while(std::cin >> from >> to) 
    {
        std::cout << sum_formula(num, from, to) << std::endl; //两个方法二选一。公 式更快。 
    }
    return 0;
}
