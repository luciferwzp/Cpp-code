//读入一个字符串str，输出字符串str中的连续最长的数字串
//输入描述： 个测试输入包含1个测试用例，一个字符串str，长度不超过255。
//输出描述： 在一行内输出str中里连续最长的数字串。 
//示例1:
//输入abcd12345ed125ss123456789
//输出123456789

#include<iostream> 
#include<string> 
using namespace std;
int main() 
{ 
    string str,res,cur;
    cin>>str; 
    for(int i=0; i<=str.length(); i++)
    { 
        // 数字+=到cur
        if(str[i]>='0' && str[i]<='9')
        { 
            cur+=str[i];
        }
        else 
        { // 找出更长的字符串，则更新字符串 
            if(res.size() < cur.size()) 
                res=cur; 
            else
                cur.clear(); 
        } 
    }
    cout<<res; 
    return 0; 
}
