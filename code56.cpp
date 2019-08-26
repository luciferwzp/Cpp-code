//老猴子辛苦了一辈子，给那群小猴子们留下了一笔巨大的财富——一大堆桃子
//。老猴子决定把这些桃子分给小猴子。 
//第一个猴子来了，它把桃子分成五堆，五堆一样多，但还多出一个。它把剩下的一个留给老猴子，自己拿走其中的一堆。
//第二个猴子来了，它把桃子分成五堆，五堆一样多，但又多出一个。它把多出的一个留给老猴子，自己拿走 其中的一堆。
//后来的小猴子都如此照办。最后剩下的桃子全部留给老猴子。
//这里有n只小猴子，请你写个程序计算一下在开始时至少有多少个桃子，以及最后老猴子最少能得到几个桃子。

//【解题思路】：公式类推
//因为每次分5堆都会多出来1个，所以我们借给猴子们4个，以致每次都可以刚好分成5堆 并且，每次给老猴子的桃子都不在我们借出的那4个中，
//这样最后减掉4就可以得到结果。 假设最初由x个桃子，我们借给猴子4个，则此时有x+4个，
//第一个猴子得到（x+4）/5，剩余（x+4）（4/5）个 第二个猴子分完后剩余（x+4） (4/5)^2个 
//第三个猴子分完后剩余（x+4） (4/5)^3个 依次类推，第n个猴子分完后剩余（x+4）（4/5）^n
//要满足最后剩余的为整数，并且x最小，则当 x+4=5^n时，
//满足要求；此时，x=5^n - 4; 老猴子得到的数量为：x+4）*（4/5）^n + n - 4= 4^n + n - 4 
//最后的 +n是因为每个小猴子都会多出一个给老猴子，-4是还了借的4个


#include<iostream>
#include<string> 
#include<math.h>
int main()
{
    int n;
    while(std::cin >> n)
    {
        if (n == 0)
            break;
        
        long total = pow(5, n) - 4;
        long left = pow(4, n) + n - 4;
        std::cout << total << " " << left << std::endl; 
    }
    return 0; 
}
