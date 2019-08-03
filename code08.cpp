//给定一个十进制数M，以及需要转换的进制数N。
//将十进制数M转化为N进制数 
//输入描述： 输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开
//。 输出描述： 为每个测试实例输出转换后的数，每个输出占一行。
//如果N大于9，则对应的数字规则参考16进制（比如，10 用A表示，等等） 
//示例1: 输入7 2 
//输出111


#include <iostream> 
#include<string>
#include<algorithm> 
using namespace std; 
int main() {
    string s, table = "0123456789ABCDEF";
    int m, n;
    cin >> m >> n;
    bool flag = false; 

    // 如果是负数，则转成正数，并标记一下 
    if(m < 0)
    {
        m = 0 - m; 
        flag = true;
    }

    // 按进制换算成对应的字符添加到s 
    while(m)
    {
        s += table[m%n]; 
        m /= n;
    }

    if(flag) s += '-'; 
    reverse(s.begin(), s.end());
    cout<<s<<endl; 
    return 0; 
}
