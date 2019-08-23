//小东所在公司要发年终奖，而小东恰好获得了最高福利，他要在公司年会上参与一个抽奖游戏，
//游戏在一个 6*6的棋盘上进行，上面放着36个价值不等的礼物，每个小的棋盘上面放置着一个礼物，他需要从左上角开始游戏，
//每次只能向下或者向右移动一步，到达右下角停止，一路上的格子里的礼物小东都能拿到，
//请设计一个算法使小东拿到价值最高的礼物。 
//给定一个6*6的矩阵board，其中每个元素为对应格子的礼物价值,左上角为[0,0],请返回能获得的最大价值，保证每个礼物价值大于100小于1000。


//【解题思路】：
//本题需要使用动态规划求解。
//定义f(i,j)表示从左上角走到坐标(i，j)处能获得的最大奖励。
//搜索所有从左上角走到右下角的路径，找到最优路径。
//f(i,j)分三种情况：
//第一列：f(i, 0) = f(i-1, 0) + board(i, 0)
//第一行：f(0,j) = f(0, j - 1) + b(0, j)
//其它位置：f(i, j) = max{f(i-1, j), f(i, j - 1)} + board(i, j)
//最后返回右下角的值


class Bonus
{
    public:
        int getMost(vector<vector<int> > board)
        {
            int length = board.size();
            int wideth = board[0].size(); 
            vector<vector<int>> allPrice; 
            for(int i = 0; i < length; i++) 
            {
                vector<int> tmp(wideth, 0);
                allPrice.push_back(tmp);
            }
            allPrice[0][0] = board[0][0];
            for(int i = 0; i < length; i++)
            {
                for(int j = 0; j < wideth; j++)
                {
                    //如果是起点坐标，不做任何处理。
                    if(i == 0 && j == 0)
                        continue;
                    //如果走在行的临界边，也就是第一行，那么他只能向右走 
                    //向右走的时候该点就要将后面的值加起来。
                    else if(i == 0)
                    {
                        allPrice[i][j] = allPrice[i][j - 1] + board[i][j]; 
                    }
                    //如果走在列的临界边，也就是第一列，那么他只能向下走 
                    //向下走的时候该点就要将上面的值加起来。
                    else if(j == 0)
                    {
                        allPrice[i][j] = allPrice[i - 1][j] + board[i][j];
                    }
                    else 
                    {
                        //除去两个临界边，剩下的就是既能向右走，也能向下走， 
                        //这时候就要考虑走到当前点的所有可能得情况，也就是走到当前点
                        //各自路径的和是不是这些所有到达该点路径当中最大的了。
                        allPrice[i][j] = max(allPrice[i][j - 1], allPrice[i - 1][j]) + board[i] [j]; 
                    }
                }
            }
            // 返回最后一个坐标点的值，它就表示从左上角走到右下角的最大奖励
            return allPrice[length - 1][wideth - 1];
        }
};
