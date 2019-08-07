//对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
//给定一个二维数组board，代表当前棋盘，
//其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为-1代表是对方玩家的棋子。 
//测试样例： [[1,0,1],[1,-1,-1],[1,-1,0]] 
//返回：true


class Board 
{
    public:
        bool checkWon(vector<vector<int> > board) 
        {
            int row = board.size();
            //检查每一行的和是是否等于row 
            int i,j,sum;
            for(i = 0; i < row; i++) 
            {
                sum = 0; 
                for(j = 0; j < row; j++) 
                { 
                    sum += board[i][j];  
                }
                if(sum == row)
                    return true;
            }
            //检查每一列的和是是否等于row 
            for(i = 0; i < row; i++)
            {
                sum = 0; 
                for(j = 0; j < row; j++) 
                {
                    sum += board[j][i];  
                }
                if(sum == row)
                    return true;
            }
            //检查主对角线的和是是否等于row 
            sum = 0;

            for(i = 0; i < row; i++)
            {
                sum += board[i][i]; 
            }
            if(sum == row)
                return true; 
            //检查副对角线的和是是否等于row 
            sum = 0; 
            for(i = 0; i < row; i++)
            {
                sum += board[i][row-i-1];
            }
            if(sum == row)
                return true;

            return false;
        }
};
