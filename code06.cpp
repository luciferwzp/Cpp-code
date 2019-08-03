//输入n个整数，输出出现次数大于等于数组长度一半的数。
//输入描述： 每个测试输入包含 n个空格分割的n个整数，n不超过100，
//其中有一个整数出现次数大于等于n/2。 
//输出描述： 输出出现次数大于等于n/2的数。 
//示例1: 输入3 9 3 2 5 6 7 3 2 3 3 3
//输出3


#include <vector> 
#include <iostream> 
using namespace std; 
int main() {
    int n; vector <int> vec; 
    while(cin >> n) 
    vec.push_back(n); 
    
    int count = 1; 
    int temp = vec[0]; 
    for(int i = 1; i < vec.size(); ++i)
    {
        if(vec[i] == temp) 
            count++;
        else
            count--; 
        if(count == 0)
        { 
            temp = vec[i]; 
            count++;  
        }
    }
    cout << temp << endl;
    return 0;  
}
