// 输出描述： 计算整数二进制中1的个数 
// 示例1: 输入5
// 输出2

#include<iostream> 
using namespace std;
int main()
{
    int n; 
    while (cin >> n)
    {
        int count = 0;
        while (n)
        {
            if ((n & 1) == 1)
                count += 1;
            n >>= 1;
        }
        cout << count << endl;
    }
    return 0; 
}
