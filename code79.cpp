//有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，
//要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
//输入描述： 每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，接下来的一行，
//包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。
//接下来的一行包含两个整 数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。
//输出描述： 输出一行表示最大的乘积。 
//示例1: 
//输入3
//7 4 7
//2 50
//输出
//49


//【解题思路】：
//对该问题的分解是关键。 从n个学生中，选择k个，可以看成是：先从n个学生里选择最后1个，然后在剩下的里选择k-1个，
//并且让这1个和前k-1个满足约束条件 记第k个人的位置为one,则可以用 f[one][k] 表示从n个人中选择k个的方案。
//然后，它的子问题，需要从one前面的left个人里面，选择k-1个，这里left表示k-1个人中最后一个（即第k-1个）人的位置，
//因此，子问题可以表示成 f[left][k-1] .
//一般的动态规划题目，中间使用的表的最后一个元素， dp[N][K] 就是所求的结果。 但这个题目不能这样，
//因为如果那样建表，子问题就成了“在前n个学生中，取k个，使乘积最大” 然而，
//本题目有额外的限制条件“相邻两个学生的位置编号的差不超过d”就没有办法代入递推公式了， 因为子问题中本身并不包含位置信息。
//从n个学生中，选择k个，可以看成是：先从n个学生里选择最后1个，然后在剩下的里选择k-1个，并且让这1个和前k-1个满足约束条件
//记第k个人的位置为one,则可以用 f[one][k] 表示从n个人中选择k个的方案。然后，它的子问题，
//需要从one前面的left个人里面，选择k-1个，这里left表示k-1个人中最后一个（即第k-1个）人的位置，因此，子问题可以表示成 f[left][k-1] 
//其次，求最大乘积比求最大和的问题要复杂许多。求最大和的话，子问题中也只需要求最大和就行了。
//但求最大乘积的时候，在子问题中，每一步需要求最大正积和最小负积。 
//因为如果某学生的能力值为负数，乘以前面求得的最小负积，结果才是最大乘积


#include<iostream>
#include<string>
#include<vector> 
#include<limits.h> // 宏 LONG_MIN LONG_MAX
using namespace std; 
// NK表存放的是，在前n个学生中，取k个（必取第n个），所等得到的最大正乘积和最小负乘积。
long long NK_zheng[51][11];
long long NK_fu[51][11]; 
int main() 
{
    int N;
    cin >> N;
    vector<int> V(N + 1);
    for(int i = 1; i <= N; i++)
    {
        cin >> V[i];
    }
    int K, D;
    cin >> K >> D;

    // 对数组先初始化 
    for(int n = 1; n <= 50; n++)
    {
        for(int k = 1; k <= 10; k++)
        {
            NK_zheng[n][k] = LLONG_MIN; // 代表无效值 
            NK_fu[n][k] = LLONG_MAX;
        }
    }
    for(int n = 1; n <= N; n++)
    {
        if(V[n] >= 0)
            NK_zheng[n][1] = V[n];
        else
            NK_fu[n][1] = V[n]; 
    }
    for(int n = 2; n <= N; n++)
    {
        for(int k = 2; k <= K && k <= n; k++)
        {
            // 找到NK[...][k-1]中最大的正数和最小的负数。
            long long max = LLONG_MIN, min = LLONG_MAX;
            for(int temp = (k - 1 > n - D) ? (k - 1) : (n - D); temp <= n - 1; temp++)
            {
                // 起始位置很重要
                if(max < NK_zheng[temp][k - 1]) 
                    max = NK_zheng[temp][k - 1]; 
                if(min > NK_fu[temp][k - 1])
                    min = NK_fu[temp][k - 1];
            }
            if(max != LLONG_MIN)
            {
                if(V[n] >= 0)
                    NK_zheng[n][k] = max * V[n];
                else
                    NK_fu[n][k] = max * V[n];
            }
            if(min != LLONG_MAX)
            {
                if(V[n] < 0 && NK_zheng[n][k] < min * V[n])
                    NK_zheng[n][k] = min * V[n];
                else if(NK_fu[n][k] > min * V[n])
                    NK_fu[n][k] = min * V[n];
            }
        }
    }

    // 在两个表的最后一列中，找出最大的乘积。 
    long long max1 = LLONG_MIN, max2 = LLONG_MIN;
    for(int n = K; n <= N; n++)
    {
        if(max1 < NK_zheng[n][K])
            max1 = NK_zheng[n][K];
        if(max2 < NK_fu[n][K] && NK_fu[n][K] != LLONG_MAX)
            max2 = NK_fu[n][K]; 
    }
    max1 = max1 > max2 ? max1 : max2; 
    cout << max1 << endl;
}
