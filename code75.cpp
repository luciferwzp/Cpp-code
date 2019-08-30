//nowcoder有两盒（A、B）乒乓球，有红双喜的、有亚力亚的……现在他需要判别A盒是否包含了B盒中所有种类，
//并且每种球的数量不少于B盒中的数量，该怎么办呢？ 
//输入描述： 输入有多组数据。 每组数据包含两个字符串A、B，代表A盒与B盒中的乒乓球，每个乒乓球用一个大写字母表示，
//即相同类型的乒乓球为相同的大写字母。 字符串长度不大于10000。
//输出描述： 每一组输入对应一行输出：如果B盒中所有球的类型在A中都有，并且每种球的数量都不大于A，则输 出“Yes”；否则输出“No”。
//示例1:
//输入
//ABCDFYE
//CDE ABCDGEAS CDECDE
//输出
//Yes
//No



//【解题思路】：
//借助 map 统计出每个盒子中的每种球的类别和数目. 然后遍历其中的一个 map 和另外一个 map 进行对比即可.
//具体细节参考代码注释.


#include<iostream> 
#include<string> 
#include<map> 
using namespace std;
int main() 
{
    string str, res;
    while(cin >> str >> res)
    {
        // sta 这个变量表示当前是否满足 B 盒的球在 A 盒中存在, 并且数目不大于 A 盒.
        bool sta = true;
        // strdata 保存了 A 盒的球. key 为球的种类, value 为球的数目 
        // resdata 保存了 B 盒的球. key 为球的种类, value 为球的数目 
        map<char, int> strdata, resdata;
        // 统计两个盒子中的球的类别和数目 
        for(auto c : str) 
            strdata[c]++;
        for(auto c : res) 
            resdata[c]++; 
        // 在 B 盒中遍历球的种类, 和 A 盒的同类球进行数目对比.
        for(map<char, int>::iterator it = resdata.begin(); it != resdata.end(); it++) 
        {
            // 只要有一种球数目不满足条件, 就用 sta 标记为 false
            // 反之, 必须所有种类的球都能够满足条件, 才能保持为 true
            if(strdata[it->first] < it->second) 
            {
                sta = false; 
                break; 
            }
        }
        if(true == sta) 
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
