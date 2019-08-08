//功能: 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1 
//输入: 一个byte型的数字 
//输出: 无 
//返回: 对应的二进制数字中1的最大连续数 
//输入描述： 输入一个byte数字 
//输出描述： 输出转成二进制之后连续1的个数 
//示例1: 输入3
//输出2



#include<iostream> 
#include<string> 
#include<algorithm>
using namespace std;
int main() 
{ 
    int n;
    while(cin >> n) 
    { 
        int count = 0, maxCount = 0;
        // n右移32次就变为0 
        while(n)
        { 
            //获取当前位的二进制值 
            if(n & 1)
            {
                //如果1的值连续，计数累加，并且跟新最大计数 
                ++count;
                maxCount = max(count, maxCount);
            }
            else
            { 
                //如果1的值不连续，重新累加 
                count = 0;
            }

            //右移一次，为获取下一位二进制值做准备 
            n = n >> 1;
        }
        cout << maxCount << endl; 
    }
    return 0; 
}
