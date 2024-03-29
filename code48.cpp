//定义一个二维数组N*M（其中2<=N<=10;2<=M<=10），
//如5 × 5数组下所示： int maze[5][5] =
//{ 
//0, 1, 0, 0, 0,
//0, 1, 0, 1, 0,
//0, 0, 0, 0, 0,
//0, 1, 1, 1, 0,
//0, 0, 0, 1, 0,
//};
//它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，
//要求编程序找 出从左上角到右下角的最短路线。
//入口点为[0,0],既第一空格是可以走的路。 
//Input 一个N × M的二维数组，表示一个迷宫。数据保证有唯一解,不考虑有多解的情况，即迷宫只有一条通道。
//Output 左上角到右下角的最短路径，格式如样例所示。
//Sample Input 
//0 1 0 0 0
//0 1 0 1 0
//0 0 0 0 0 
//0 1 1 1 0
//0 0 0 1 0
//Sample Output
//(0, 0)
//(1, 0) 
//(2, 0) 
//(2, 1) 
//(2, 2)
//(2, 3) 
//(2, 4) 
//(3, 4) 
//(4, 4)
//输入描述： 输入两个整数，分别表示二位数组的行数，列数。再输入相应的数组，其中的1表示墙壁，0表示可以走的路。
//数据保证有唯一解,不考虑有多解的情况，即迷宫只有一条通道。
//输出描述： 左上角到右下角的最短路径，格式如样例所示。 
//示例1: 输入5 5
//0 1 0 0 0 
//0 1 0 1 0 
//0 0 0 0 0
//0 1 1 1 0
//0 0 0 1 0
//输出
//(0,0)
//(1,0)
//(2,0)
//(2,1) 
//(2,2)
//(2,3) 
//(2,4)
//(3,4) 
//(4,4)


//【解题思路】：
//本题可用回溯法求解 具体步骤为：
//1. 首先将当前点加入路径，并设置为已走
//2. 判断当前点是否为出口，是则输出路径，保存结果；跳转到4 3. 依次判断当前点的上、下、左、右四个点是否可走，如果可走则递归走该点
//4. 当前点推出路径，设置为可走


#include<iostream>
#include<vector>
using namespace std;
int N, M;//分别代表行和列 
vector<vector<int>> maze;//迷宫矩阵 
vector<vector<int>> path_temp;//存储当前路径，第一维表示位置 
vector<vector<int>> path_best;//存储最佳路径 
void MazeTrack(int i, int j)
{
    maze[i][j] = 1;//表示当前节点已走，不可再走 
    path_temp.push_back({ i, j  });//将当前节点加入到路径中
    if(i == N - 1 && j == M - 1) //判断是否到达终点
        if(path_best.empty() || path_temp.size() < path_best.size())
            path_best = path_temp;

    if(i - 1 >= 0 && maze[i - 1][j] == 0)//探索向上走是否可行 
        MazeTrack(i - 1, j);
    if(i + 1 < N && maze[i + 1][j] == 0)//探索向下走是否可行 
        MazeTrack(i + 1, j); 
    if(j - 1 >= 0 && maze[i][j - 1] == 0)//探索向左走是否可行 
        MazeTrack(i, j - 1);
    if(j + 1 < M && maze[i][j + 1] == 0)//探索向右走是否可行 
        MazeTrack(i, j + 1);
    maze[i][j] = 0; //恢复现场，设为未走 
    path_temp.pop_back();
}
int main() 
{
    while(cin >> N >> M)
    {
        maze = vector<vector<int>>(N, vector<int>(M, 0));
        path_temp.clear();
        path_best.clear(); 
        for(auto &i : maze) 
            for(auto &j : i) 
                cin >> j;
        MazeTrack(0, 0);//回溯寻找迷宫最短通路 
        for (auto i : path_best) 
            cout << '(' << i[0] << ',' << i[1] << ')' << endl;//输出通路 
    }
    return 0;
}
