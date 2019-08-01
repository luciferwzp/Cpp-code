//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
//例如，输入”They are students.”和”aeiou
//则删除之后的第一个字符串变成”Thy r stdnts.
//” 输入描述： 每个测试输入包含2个字符串
//输出描述： 输出删除后的字符串
//示例1: 输入They are students. aeiou
//输出Thy r stdnts.
#include<iostream>
#include<string>
using namespace std; 
int main() {
  // 注意这里不能使用cin接收，因为cin遇到空格就结束了。 
  // // oj中IO输入字符串最好使用getline。
  string str1,str2;
  //cin>>str1;
  //cin>>str2;
  getline(cin, str1);
  getline(cin, str2);
  // 使用哈希映射思想先str2统计字符出现的次数 
  int hashtable[256] = {0}; 
  for(size_t i = 0; i < str2.size(); ++i)
  {
    hashtable[str2[i]]++; 
  }
  // 遍历str1，str1[i]映射hashtable对应位置为0，则表示这个字符在 
  // str2中没有出现过，则将他+=到ret。注意这里最好不要str1.erases(i)
  //  因为边遍历，边erase，容易出错。 
  string ret;
  for(size_t i = 0; i < str1.size(); ++i)
  {
    if(hashtable[str1[i]] == 0)

      ret += str1[i];
  }
  cout<<ret<<endl; 
  return 0;
}
