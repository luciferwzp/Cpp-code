//Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。 
//许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。
//编辑距离的算法是首先由俄国科学家Levenshtein提出的，故又叫Levenshtein Distance。
//Ex：字符串A:abcdefg
//字符串B: abcdef
//通过增加或是删掉字符”g”的方式达到目的
//。这两种方案都需要一次操作。把这个操作所需要的次数定义为两个字符串的距离。
//要求： 给定任意两个字符串，写出一个算法计算它们的编辑距离。 
//请实现如下接口 /*功能：计算两个字符串的距离       *输入： 字符串A和字符串B          *输出：无 
//*返回：如果成功计算出字符串的距离，否则返回-1 
//*/ public static int style="font-family: "courier new";font-size: 13.0px;"> calStringDistance ( style="background: silver;">String charA, String charB ) { return 0; }
//输入描述： 输入两个字符串 
//输出描述： 得到计算结果
//示例1: 输入abcdefg abcdef
//输出1


//【解题思路】：
//本题需要用动态规划解题 
//状态： 子状态：word1的前1，2，3，...m个字符转换成word2的前1，2，3，...n个字符需要的编辑距离
//F(i,j):word1的前i个字符于word2的前j个字符的编辑距离 
//状态递推： F(i,j) = min { F(i-1,j）+1, F(i,j-1) +1, F(i-1,j-1) +(w1[i]==w2[j]?0:1) }
//上式表示从删除，增加和替换操作中选择一个最小操作数 F(i-1,j): w1[1,...,i-1]于w2[1,...,j]的编辑距离，
//删除w1[i]的字符--->F(i,j) F(i,j-1): w1[1,...,i]于w2[1,...,j-1]的编辑距离，增加一个字符---
//>F(i,j) F(i-1,j-1): w1[1,...,i-1]于w2[1,...,j-1]的编辑距离，如果w1[i]与w2[j]相同， 不做任何操作，
//编辑距离不变，如果w1[i]与w2[j]不同，替换w1[i]的字符为w2[j]--->F(i,j) 初始化： 初始化一定要是确定的值，
//如果这里不加入空串，初始值无法确定 F(i,0) = i :word与空串的编辑距离，删除操作 F(0,i) = i :空串与word的编辑距离，
//增加操作 返回结果：F(m,n)


#include<string> 
#include<iostream>
#include<vector> 
using namespace std;
int minDistance(string word1, string word2)
{
    // word与空串之间的编辑距离为word的长度
    if(word1.empty() || word2.empty())
    {
        return max(word1.size(), word2.size());
    }
    int len1 = word1.size();
    int len2 = word2.size();
    // F(i,j)初始化 
    vector<vector<int>> f(1 + len1, vector<int>(1 + len2, 0));
    for(int i = 0; i <= len1; ++i) 
    {
        f[i][0] = i;
    }
    for(int i = 0; i <= len2; ++i)
    {
        f[0][i] = i; 
    }
    for(int i = 1; i <= len1; ++i)
    {
        for(int j = 1; j <= len2; ++j)
        {
            // F(i,j) = min { F(i-1,j）+1, F(i,j-1) +1, F(i-1,j-1) + //(w1[i]==w2[j]?0:1) }
            // 判断word1的第i个字符是否与word2的第j个字符相等 
            if(word1[i - 1] == word2[j - 1])
            {
                f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
                // 字符相等，F(i-1,j-1)编辑距离不变
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            }
            else 
            {
                f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
                // 字符不相等，F(i-1,j-1)编辑距离 + 1 
                f[i][j] = min(f[i][j], 1 + f[i - 1][j - 1]);
            }
        }
    }
    return f[len1][len2];
}
int main()
{
    string a,b; 
    while(cin >> a >> b)
        cout<<minDistance(a, b)<<endl;
    return 0; 
}
