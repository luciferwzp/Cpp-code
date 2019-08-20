//问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。
//现要求各位实现字符串通配符的算法。
//要求： 实现如下2个通配符：
//*：匹配0个或以上的字符（字符由英文字母和数字0-9组成，不区分大小写。下同）
//？：匹配1个字符 
//输入：  通配符表达式； 一组字符串。 
//输出： 返回匹配的结果，正确输出true，错误输出false
//输入描述： 先输入一个带有通配符的字符串，再输入一个需要匹配的字符串 
//输出描述： 返回匹配的结果，正确输出true，错误输出false
//示例1: 输入te?t*.*
//txt12.xls
//输出false


//【解题思路】：
//本题可以通过递归求解。从前向后一次匹配，遇到相同字符，都向后移动一个字符，如果通配符遇到"?"，则不需匹配，自动跳过一个字符，如果通配符遇到"*"，则可以匹配任意多个字符，包括0个，此时可以有三种选择，
//1，匹配0 个，通配符向后移动一个字符，字符串不动。
//2，匹配1个，通配符和字符串都向后移动一个字符。
//3，匹配多个，通 配符不动，字符串向后移动一个字符。
//递归的终止条件：通配符或者字符串遇到'\0'。当他们同时结束。


#include<iostream>
#include<string>
using namespace std; 
bool match(const char* pattern, const char *str)
{
    //当前字符结束，返回true
    if(*pattern == '\0' && *str == '\0')
        return true;
    //两个字符串有一个先结束，则返回false
    if(*pattern == '\0' || *str == '\0')
        return false;

    if(*pattern == '?') 
    {
        //遇到?号，匹配一个字符，跳过一个位置
        return match(pattern + 1, str + 1);
    }
    else if(*pattern == '*') 
    {
        // 遇到*号，匹配0个(str不挪动)，1个（两者都向前挪动一个字符）或多个(str向前挪动一个字符) 
        return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1); 
    }
    else if(*pattern == *str)
    {
        //如果当前字符相等，匹配下一个字符
        return match(pattern + 1, str + 1);
    }
    return false;
}
int main() 
{
    string pattern, str;
    while(cin >> pattern >> str)
    {
        bool ret = match(pattern.c_str(), str.c_str());
        if(ret)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
