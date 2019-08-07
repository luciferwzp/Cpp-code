//密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。
//一、密码长度: 
//5分: 小于等于4个字符 
//10分: 5到7个字符 
//25分: 大于等于8个字符

//二、字母: 
//0分: 没有字母 
//10分: 全都是小（大）写字母 
//20分: 大小写混合字母 

//三、数字:
//0分: 没有数字 
//10分: 1个数字
//20分: 大于1个数字 

//四、符号:
//0分: 没有符号 
//10分: 1个符号 
//25分: 大于1个符号 

//五、奖励: 
//2分: 字母和数字 
//3分: 字母、数字和符号 
//5分: 大小写字母、数字和符号 

//最后的评分标准: 
//>= 90: 非常安全 
//>= 80: 安全（Secure） 
//>= 70: 非常强 
//>= 60: 强（Strong） 
//>= 50: 一般（Average）
//>= 25: 弱（Weak） 
//>= 0: 非常弱
//对应输出为： 
//VERY_WEAK, WEAK, AVERAGE, STRONG, VERY_STRONG, SECURE, VERY_SECURE
//请根据输入的密码字符串，进行安全评定。 

//注：
//字母：a-z, A-Z 
//数字：-9 
//符号包含如下： (ASCII码表可以在UltraEdit的菜单view->ASCII Table查看) 
//!"#$%&'()*+,-./ (ASCII码：x21~0x2F)
//:;<=>?@ (ASCII<=><=><=><=><=>码：x3A~0x40)
//[\]^_` (ASCII码：x5B~0x60)
//{|}~ (ASCII码：x7B~0x7E) 

//接口描述： 
//Input Param 
//String pPasswordStr: 密码，以字符串方式存放。 
//Return Value 根据规则评定的安全等级。

//public static Safelevel GetPwdSecurityLevel(String pPasswordStr)
//{
///*在这里实现功能*/ 
//return null;
//}

// 输入描述： 输入一个string的密码 
// 输出描述： 输出密码等级 
// 示例1: 输入 38$@NoNoNo
// 输出 VERY_SECURE





#include<iostream> 
#include<string> 
using namespace std; 
int numChar(string str, int k) 
{ 
    //根据ASCII码判断字母大小写 
    int small = 0;
    int big = 0; 
    for(int i = 0; i < k; i++)
    {
        if(str[i] >= 65 && str[i] <= 90) 
            big++; 
        else if(str[i] >= 97 && str[i] <= 122) 
            small++; 
    }
    if((small + big) == 0)
        return 0; 
    else if(small == k || big == k)
        return 10;
    else if(small > 0 && big > 0) 
        return 20; 

    return 0;
}
int numNumber(string str, int k)
{
    //根据ASCII码判断数字个数，减去字符‘0’之后在0~9之间的即为数字
    int num = 0;
    for(int i = 0; i < k; i++)
    {
        if(str[i] - '0' >= 0 && str[i] - '0' <= 9) 
            num++;  
    }
    if(num == 0) 
        return 0; 
    else if(num == 1) 
        return 10;
    else
        return 20; 
}
int numSymbal(string str, int k)
{
    int num = 0;
    for(int i = 0; i < k; i++)
    {
        //除去字母，数字，其它都为符号 
        if(!(str[i] >= 65 && str[i] <= 90) 
                && !(str[i] >= 97 && str[i] <= 122) 
                && !(str[i] - '0' >= 0 
                    && str[i] - '0' <= 9)) 
            num++; 
    }
    if(num == 0) 
        return 0; 
    else if(num == 1)
        return 10; 
    else
        return 25;
}
int main() 
{ 
    string str;
    while(cin >> str)
    {
        int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0; 
        int k = str.size();
        if(k <= 4) 
            sum1 = 5; 
        else if(k >= 8) 
            sum1 = 25;
        else 
            sum1 = 10; 
        sum2 = numChar(str, k);
        sum3 = numNumber(str, k);
        sum4 = numSymbal(str, k); 
        if((sum2 > 0) && (sum3 > 0) && (sum4 > 0)) 
        { 
            if(sum2 == 10) 
                sum5 = 3; 
            else
                sum5 = 5; 
        }
        else if(sum2 > 0 && sum3 > 0 && sum4 == 0)
            sum5 = 2; 
        if(sum1 + sum2 + sum3 + sum4 + sum5 >= 90)
            cout << "VERY_SECURE" << endl;
        else if(sum1 + sum2 + sum3 + sum4 + sum5 >= 80) 
            cout << "SECURE" << endl; 
        else if(sum1 + sum2 + sum3 + sum4 + sum5 >= 70) 
            cout << "VERY_STRONG" << endl;
        else if(sum1 + sum2 + sum3 + sum4 + sum5 >= 60) 
            cout << "STRONG" << endl;
        else if(sum1 + sum2 + sum3 + sum4 + sum5 >= 50)
            cout << "AVERAGE" << endl;
        else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 25) 
            cout << "WEAK" << endl;
        else
            cout << "VERY_WEAK" << endl;
    }
    return 0;
}
