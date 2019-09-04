//Emacs号称神的编辑器，它自带了一个计算器。与其他计算器不同，它是基于后缀表达式的，即运算符在操作数的后面。
//例如“2 3 +”等价于中缀表达式的“2 + 3”。 请你实现一个后缀表达式的计算器。
//输入描述： 输入包含多组数据。 每组数据包括两行：第一行是一个正整数n (3≤n≤50)；紧接着第二行包含n个由数值和运算符组成的列表。
//“ + - * / ”分别为加减乘除四则运算，其中除法为整除，即“5/3=1”。 
//输出描述： 对应每一组数据，输出它们的运算结果。
//示例1:
//输入
//3
//2 3 + 
//5
//2 2 + 3 * 
//5
//2 2 3 + * 
//输出
//5
//12
//10


//【解题思路】
//循环输入，获取逆波兰表达式，然后进行以下补助，直到测试完所有的测试用例：
//1. 遇到数字字符串，将该数字字符串转化为数字然后入栈。
//2. 遇到操作符时，从栈顶取两个数字，然后进行该运算符所对应运算，完成好将结果入栈，注意：先取到的数字为运算符的右操作数。
//3. 继续1和2，直到处理完所有的字符串，最终栈顶元素即为所要结果。


#include<iostream> 
#include<stack>
#include<string>
#include<vector>
using namespace std; 
int main()
{
    int n;
    int a,b,ret;
    while(cin >> n)
    {
        if(n == 0)
            continue;
        vector<string> s(n); 
        stack<int> st;
        for(int i = 0; i < n; i++)
        { 
            cin >> s[i];
        } 
        for(int i = 0; i < n; i++)
        {
            if(s[i][0] >= '0' && s[i][0] <= '9')
            {
                st.push(atoi(s[i].data())); 
            }
            else
            {
                a = st.top(); 
                st.pop();
                b = st.top();
                st.pop(); 
                switch(s[i][0])
                {
                    case '+': st.push(a+b);break;
                    case '-': st.push(b-a);break;
                    case '*': st.push(a*b);break; 
                    case '/': st.push(b/a);break;
                }
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}
