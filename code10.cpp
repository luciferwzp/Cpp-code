//一个数组有 N 个元素，求连续子数组的最大和。 
//例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3 
//输入描述： 输入为两行。 
//第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素 
//第二行为n个数，即每个元素,每个 整数都在32位int范围内。以空格分隔。
//输出描述： 所有连续子数组中和最大的值。
//示例1: 
//输入3 -1 2 1 
//输出3


#include <iostream> 
#include<vector> 
using namespace std; 
int main() 
{ 
    int size; 
    cin >> size; 
    vector<int> nums(size); 
    for(size_t i = 0; i < size; ++i) 
        cin >> nums[i]; 

    int result = nums[0];
    int sum1 = 0, sum2 = 0; 
    for (int i = 0; i < nums.size(); i++) 
    { 
        // 计算到num[i]的子数组的最大和 
        sum2 = sum1 >= 0 ? sum1+nums[i] : nums[i]; 
        if(sum2 > result) 
            result = sum2;

        if(sum2 < 0) 
            sum2 = 0; 
            
        sum1 = sum2;
    }
    cout << result << endl; 
    return 0; 
}
