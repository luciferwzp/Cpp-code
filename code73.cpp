//上图是一个电话的九宫格，如你所见一个数字对应一些字母，因此在国外企业喜欢把电话号码设计成与自己公司名字相对应。
//例如公司的Help Desk号码是4357，因为4对应H、3对应E、5对应L、7对应P，因此4357 就是HELP。
//同理，TUT-GLOP就代表888-4567、310-GINO代表310-4466。 NowCoder刚进入外企，并不习惯这样的命名方式，
//现在给你一串电话号码列表，请你帮他转换成数字形式 的号码，并去除重复的部分。 
//输入描述： 输入包含多组数据。 每组数据第一行包含一个正整数n（1≤n≤1024）。
//紧接着n行，每行包含一个电话号码，电话号码仅由连字符“-”、数字和大写字母组成
//。 没有连续出现的连字符，并且排除连字符后长度始终为7（美国电话号码只有7位）。
//输出描述： 对应每一组输入，按照字典顺序输出不重复的标准数字形式电话号码，即“xxx-xxxx”形式
//。 每个电话号码占一行，每组数据之后输出一个空行作为间隔符。
//示例1: 输入
//12
//4873279 
//ITS-EASY 
//888-4567
//3-10-10-10 
//888-GLOP 
//TUT-GLOP 
//967-11-11
//310-GINO 
//F101010 
//888-1200
//-4-8-7-3-2-7-9-
//487-3279 
//4UTT-HELP 
//TUT-GLOP
//310-GINO
//000-1213 
//输出
//310-1010
//310-4466
//487-3279
//888-1200
//888-4567
//967-1111
//000-1213
//310-4466 
//888-4357 
//888-4567


//【解题思路】：
//1. 先用hash表存储字母和数字之间的映射关系
//2. 每次读到一个字符, 去hash表中查找, 并进行处理即可


// 借助 hash 表完成字母和数字之间的转换即可. 注意处理大小写的情况.
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional> 
#include<map>
#include<set>
#include<unordered_set> 
#include<unordered_map>
#include<exception>
#include<iomanip>
#include<memory> 
#include<sstream> 
#define INF 1000000 
using namespace std;
int main(int argc, char** argv) 
{
    unordered_map<char, char> dic;
    dic.emplace('A', '2'); 
    dic.emplace('B', '2');
    dic.emplace('C', '2'); 
    dic.emplace('D', '3'); 
    dic.emplace('E', '3');
    dic.emplace('F', '3');
    dic.emplace('G', '4'); 
    dic.emplace('H', '4');
    dic.emplace('I', '4');
    dic.emplace('J', '5');
    dic.emplace('K', '5');
    dic.emplace('L', '5');
    dic.emplace('M', '6');
    dic.emplace('N', '6');
    dic.emplace('O', '6');
    dic.emplace('P', '7'); 
    dic.emplace('Q', '7');
    dic.emplace('R', '7');
    dic.emplace('S', '7'); 
    dic.emplace('T', '8'); 
    dic.emplace('U', '8');
    dic.emplace('V', '8'); 
    dic.emplace('W', '9');
    dic.emplace('X', '9'); 
    dic.emplace('Y', '9');
    dic.emplace('Z', '9');
    int n; 
    while(cin >> n && n > 0)
    {
        set<string> hs;
        string s;
        for(int i = 0; i < n; ++i)
        {
            cin >> s; 
            string p = "";
            for(auto& c : s)
            {
                if(isdigit(c))
                    p += c;
                else if(isupper(c)) 
                    p += dic[c]; 
            }
            if(p.size() != 7)
                continue;
            p = p.substr(0, 3) + "-" + p.substr(3); 
            hs.emplace(p); 
        }
        for(auto& phone : hs)
            cout << phone << endl;
        cout << endl;
    }
    return 0;
}
