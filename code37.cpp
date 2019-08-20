//有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以 多少瓶汽水喝？”答案是5瓶
//，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。
//然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。
//如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？ 
//输入描述： 输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数n（1<=n<=100），表示小张手上的空汽水瓶数。n=0表示输入结束，你的程序不应当处理这一行。
//输出描述： 对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。
//示例1: 输入310810
//输出1540


//【解题思路】：
//本题题意简单，每次空瓶的数量除以2，直到最后空瓶的数量少于两瓶，就累加到了课兑换的数量。


#include<iostream> 
#include<string> 
using namespace std;
int calculateNum(int num)
{
    //总兑换数 
    int sum = 0;
    while(num > 1)
    {
        //每三瓶换一瓶 
        int result = num / 3;
        //剩余不足三瓶的先保留 
        int reminder = num % 3;
        sum = sum + result; 
        //下一次可以兑换的空瓶 
        num = result + reminder;
        if(num == 2)
        {
            ++sum;
            break;
        }
    }
    return sum;
}
int main()
{
    int number;
    while(cin >> number)
    {
        cout << calculateNum(number) << endl;
    }
    return 0;
}
