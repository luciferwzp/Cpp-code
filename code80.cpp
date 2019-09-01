//搜狐员工小王最近利用假期在外地旅游，在某个小镇碰到一个马戏团表演，精彩的表演结束后发现团长正和大伙在帐篷前激烈讨论，
//小王打听了下了解到， 马戏团正打算出一个新节目“最高罗汉塔”，即马戏团员叠罗汉表演
//。考虑到安全因素，要求叠罗汉过程中，站 在某个人肩上的人应该既比自己矮又比自己瘦，或相等。
//团长想要本次节目中的罗汉塔叠的最高，由于人数众多，正在头疼如何安排人员的问题。小王觉得这个问题很简单，
//于是统计了参与最高罗汉塔表演的所有团员的身高体重，并且很快找到叠最高罗汉塔的人员序列。 
//现在你手上也拿到了这样一份身高体重表，请找出可以叠出的最高罗汉塔的高度，这份表中马戏团员依次编号为1到N。
//输入描述： 首先一个正整数N， 之后N行，每行三个数，分别对应马戏团员编号，体重和身高。
//输出描述： 正整数m，表示罗汉塔的高度。 
//示例1: 
//输入
//6
//1 65 100
//2 75 80
//3 80 100 
//4 60 95 
//5 82 101
//6 81 70
//输出
//4


//【解题思路】：
//参看 https://www.cnblogs.com/wxjor/p/5524447.html


#include<iostream> 
#include<algorithm>
#include<vector>
using namespace std;
struct player
{
    int w;
    int h;
};
bool com_w(player p1,player p2)
{
    //按照体重从小到大排序 
    if(p1.w != p2.w)
        return p1.w <= p2.w;
    //在体重相等的条件下，身高高的在前（在上）
    else 
        return p1.h>p2.h;
}
int main(void)
{
    int N;
    int h;
    int w; 
    int index;
    vector<player> p;
    while(cin >> N) 
    {
        p.clear();

        // 处理数据
        for(int i = 0;i < N;i++) 
        {
            player pt;
            cin >> index >> w >> h;
            pt.w = w;
            pt.h = h;
            p.push_back(pt); 
        }
        sort(p.begin(),p.end(),com_w);

        //按照身高求最大上升子序列(此处为核心代码)
        //关于最大上升子序列问题的讲解, 参看 https://www.cnblogs.com/wxjor/p/5524447.html
        int dp2[N+1];
        int max = 0;
        dp2[0] = 1;
        for(int i = 1;i < N;i++) 
        {
            dp2[i] = 1;
            for(int j = 0;j < i;j++)
            {
                if(p[j].h <= p[i].h && dp2[j]+1 > dp2[i]) dp2[i] = dp2[j] + 1;
            }
        }
        // 找出 dp2 中最大的数据, 即为最终结果
        for(int i = 0;i < N;i++)
            if(max < dp2[i]) 
                max = dp2[i];
        cout << max << endl;
    }
    system("pause");
    return 0;
}

