//在命令行输入如下命令： xcopy /s c:\ d:\， 各个参数如下：
//参数1：命令字xcopy 
//参数2：字符串/s 
//参数3：字符串c:\ 
//参数4: 字符串d:\ 
//请编写一个参数解析程序，实现将命令行各个参数解析出来。


//解析规则： 1.参数分隔符为空格 2.对于用“”包含起来的参数，如果中间有空格，不能解析为多个参数。
//比如在命令行输入 xcopy /s “C:\program files” “d:\”时，参数仍然是4个，
//第3个参数应该是字符串C:\program files，而不是 C:\program，注意输出参数时，需要将“”去掉，引号不存在嵌套情况。
//3.参数不定长 4.输入由用例保证，不会出现不符合要求的输入 
//输入描述： 输入一行字符串，可以有空格 
//输出描述： 输出参数个数，分解后的参数，每个参数都独占一行 
//示例1: 输入 xcopy /s c:\\ d:\\ 
//输出 
//4 
//xcopy    /s    c:\\    d:\\


#include <iostream> 
#include <string>
using namespace std;
int main() 
{
    string str;
    while(getline(cin, str)) 
    {
        int count = 0;
        //首先计算参数数量 
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == ' ') 
                count++; 
            //如果是双引号，向后遍历，直到下一个双引号结束 
            if(str[i] == '"')
            {
                do
                {
                    i++; 
                } while (str[i] != '"');
            }
        }
        //以空格计算个数，空格数量比参数个数少1 
        cout << count + 1 << endl;
        //用flag表示是否包含双引号，0表示有双引号
        //双引号中的空格要打印出来 
        //用异或改变flag的值，两个双引号可以使flag复原 
        int flag = 1;
        for(int i = 0; i < str.size(); i++) 
        {
            //有双引号，flag通过异或变为0，下一次再遇到双引号，flag置为1 
            if(str[i] == '"')
                flag ^= 1;
            //双引号和普通空格不打印
            if(str[i] != ' ' && str[i] != '"')
                cout << str[i];
            //双引号中的空格要打印 
            if(str[i] == ' ' && (!flag))
                cout << str[i];
            //遇到双引号之外的空格就换行 
            if (str[i] == ' ' && flag)
                cout << endl;
        }
        cout << endl;
    }
    return 0; 
}
