//有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，
//假如兔子都不死，问每个月的兔子总数为多少？ 
///** * 统计出兔子总数。       ** @param monthCount 第几个月            * @return 兔子总数 
//*/ public static int getTotalCount(int monthCount)
//{
//return 0; 
//}
//输入描述： 输入int型表示month 
//输出描述： 输出兔子总数int型 
//示例1: 输入9
//输出34


//【解题思路】： 第n个月的兔子数量由两部分组成，一部分是上个月的兔子f(n-1)，另一部是满足3个月大的兔子，会生一只兔子f(n- 2)。所以第n个月兔子总数： f(n) = f(n - 1) + f(n - 2)。本题是在变相考察斐波那契数列。


#include<iostream>
using namespace std;
int main()
{
    int month;
    while(cin >> month)
    {
        int first = 1;
        int second = 1;
        int result; 
        for(int i = 3; i <= month; ++i)
        {
            result = first + second;
            first = second;
            second = result;
        }
        cout << result << endl;
    }
    return 0;  
}
