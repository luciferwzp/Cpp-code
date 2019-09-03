//有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。
//你站在其中一块黑色的瓷砖上，只能向 相邻的（上下左右四个方向）黑色瓷砖移动。
//请写一个程序，计算你总共能够到达多少块黑色的瓷砖。
//输入描述： 输入包含多组数据。 每组数据第一行是两个整数 m 和 n（1≤m, n≤20）。紧接着 m 行，每行包括 n 个字符
//。每个字符表示一块瓷砖的颜色，规则如下：
//1. “.”：黑色的瓷砖；
//2. “#”：白色的瓷砖；
//3. “@”：黑色的瓷砖，并且你站在这块瓷砖上。
//该字符在每个数据集合中唯一出现一次。 
//输出描述： 对应每组数据，输出总共能够到达多少块黑色的瓷砖。 
//示例1:
//输入
//  9 6
//  ....#. 
//  .....# 
//  ......
//  ......
//  ...... 
//  ......
//  ......
//  #@...# 
//  .#..#.
//输出
//45


//[解题思路] 该问题可以采用深度优先遍历的方式，统计所有的可能性，具体细节见代码 


/* DFS问题 */
#include<iostream> 
#include<fstream> 
#include<vector> 
#include<queue> 
using namespace std; 
struct pos
{
    int x, y;
};
int bfs(vector<vector<char> > & map, vector<vector<bool> > & visit, pos & start)
{
    const int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
    queue<pos> que; 
    int count = 0; 
    int m = map.size(), n = map[0].size(); 
    que.push(start);
    visit[start.x][start.y] = true; 
    ++count;
    while(!que.empty())
    {
        pos cur = que.front(), next;
        que.pop();
        for(int i = 0; i < 4; ++i)
        {
            next.x = cur.x + dir[i][0];
            next.y = cur.y + dir[i][1];
            if(next.x >= 0 && next.x < m && next.y >= 0 && next.y < n && 
                    \ !visit[next.x][next.y] && map[next.x][next.y] == '.')
            {
                que.push(next); 
                visit[next.x][next.y] = true; ++count;
            } 
        }
    }
    return count;
}

int main()
{
    int m, n; 
    while(cin >> m >> n && (m*n))
    {
        pos start; 
        vector<vector<char> > map(m, vector<char>(n)); 
        vector<vector<bool> > visit(m, vector<bool>(n));
        for(int i = 0; i < m; ++i) 
            for(int j = 0; j < n; ++j)
            {
                visit[i][j] = false;
                cin >> map[i][j]; 
                if(map[i][j] == '@')
                    start.x = i, start.y = j;
            }
        cout << bfs(map, visit, start) << endl; 
    }
    return 0;
}
