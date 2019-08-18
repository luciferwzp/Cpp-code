//请设计一个算法完成两个超长正整数的加法。
//接口说明 /*请设计一个算法完成两个超长正整数的加法。
//输入参数： String addend：加数      String augend：被加数    返回值：  加法结果 
//*/public String AddLongInteger(String addend, String augend) 
//{ /*在这里实现功能*/ return null;  }
// 输入描述： 输入两个字符串数字 
// 输出描述： 输出相加后的结果，string型 
// 示例1: 输入99999999999999999999999999999999999999999999999999 1
// 输出100000000000000000000000000000000000000000000000000


//【解题思路】： 加法运算，每一位的值等于当前对应位的两数之和+进位。
//由于是加法，所以当前位的和最多是19（9 + 9 + 进位1)， 所以产生的进位最多为1。
//故第一步：计算对应位的和，对应位相加 + 上一位的进位
//第二步：更新当前位的值， 和 % 10 ，把值转成字符（和 -'0'）存入字符结果中 
//第三步：更新进位， 和 / 10， 然后计算下一位的值
//最后一步：如果计算完之后，进位为1，说明最高位产生了进位，所以需要再加一位，才是最后的结果。
//结果产生之后，需要逆置，得到最终结果。


#include<string>
#include<iostream> 
#include<algorithm> 
using namespace std;
string addStrings(string num1, string num2)
{
    //由低位向高位相加 
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    string result = "";
    //当前位的相加结果 
    int carry = 0;
    while(i >= 0 || j >= 0)
    {
        if(i >= 0)
        {
            carry += num1[i] - '0';
        }
        if(j >= 0) 
        {
            carry += num2[j] - '0';
        }
        //当前为的最大值不大于10
        result += (char)(carry % 10 + '0');
        //如果大于10,向上进一位 
        carry /= 10;
        i--;
        j--;
    }
    //相加完之后，如果还有进位，则再加1
    if(carry == 1)
    {
        result += '1';
    }
    //整体逆置
    reverse(result.begin(), result.end()); 
    return result;
}
int main() 
{
    string s1, s2;
    while(cin>>s1>>s2)
    {
        cout << addStrings(s1, s2) << endl; 
    }
    return 0;
}
