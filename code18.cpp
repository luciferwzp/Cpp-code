//请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）
//沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，
//即：只能往右和往下走，不能往左和往上走。 
//输入描述： 输入两个正整数 
//输出描述： 返回结果 
//示例1:
//输入 22
//输出 6


#include<iostream> 
using namespace std;
int pathNum(int n,int m)
{ 
    if(n > 1 && m > 1) 
        //b情况，递归 
        return pathNum(n-1,m) + pathNum(n,m-1); 
    else if(((n >= 1)&&(m == 1))||((n == 1)&&(m >= 1))) 
        // a情况，终止条件 
        return n + m; 
    else
        //格子为0时， 路径为0 
        return 0;
}
int main() 
{
    int n,m;
    while(cin >> n >> m)
    { 
        cout << pathNum(n,m) << endl; 
    }
    return 0;
}
