//牛牛举办了一次编程比赛,参加比赛的有3*n个选手,每个选手都有一个水平值a_i.
//现在要将这些选手进行组队,一 共组成n个队伍,即每个队伍3人.
//牛牛发现队伍的水平值等于该队伍队员中第二高水平值。
#include<iostream> 
#include<algorithm>
#include<vector> 
using namespace std; 
int main() { 
  // IO型OJ可能会有多组测试用例，所以这里要持续接收输入多组测试用例。 
  int n; 
  while (cin >> n) 
  { 
    long long sum = 0; 
    vector<int> a; 
    a.resize(3*n); 
    for (int i = 0; i < (3 * n); i++) 
    { 
      cin >> a[i];
    }
    /*排序，然后取下标为3n - 2，3n - 4 ，3n - 4... n+2，n位置的元素累加即可，
     * 相当下标为[0,n-1]的n个数做每组的最左边的数，
     * 剩下的2个数据两个为一组， 大的值做最右边的数，次大的做中间值，这里就是把这个次大的值加起来 */
    std::sort(a.begin(), a.end()); 
    for (int i = n; i <= 3 * n - 2; i += 2)
    {
      sum += a[i];
    }
    cout << sum << endl;
  }
}

