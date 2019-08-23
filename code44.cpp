//找出字符串中第一个只出现一次的字符
//输入描述： 输入一个非空字符串
//输出描述： 输出第一个只出现一次的字符，如果不存在输出-1
//示例1: 输入asdfasdfo
//输出o


//【解题思路】：
//用一个数组的每一个位置表示对应的位置。对应的字符位置存放字符出现的次数。统计完之后，遍历输入字符，
//遇到第一个只出现一次的字符就停止

#include<string>
#include<iostream> 
using namespace std;
int main() 
{
    string s;
    while(cin >> s)
    {
        int hashtable[256] = {0};
        for(auto& e : s)
        {
            hashtable[e]++; 
        }
        int i; 
        for(i = 0; i < s.size(); i++)
        {
            if(hashtable[s[i]] == 1) 
            {
                cout << s[i] << endl;
                break; 
            }
        }
        if(i >= s.size())
            cout << -1 << endl;
    }
    return 0;
}

