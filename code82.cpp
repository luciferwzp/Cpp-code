//对于一个矩阵，请设计一个算法从左上角(mat[0][0])开始，顺时针打印矩阵元素。 
//给定int矩阵mat,以及它的维数 n x m，请返回一个数组，数组中的元素为矩阵元素的顺时针输出。
//测试样例： 
//[[1,2],[3,4]],2,2
//返回：
//[1,2,4,3]


//【解题思路】：
//1. 先记录左上角和右下角坐标(这两个坐标就描述了一个矩形)
//2. 然后先按照顺时针打印这个矩形边上的元素
//3. 缩小矩形(也就是调整左上和右下坐标位置)
//4. 再次顺时针打印. 一直缩小到这个矩形为空即可


// 问题本身不复杂, 将思路考虑周全即可.
class Printer
{
    public: 
        vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) 
        { 
            vector<int> ret; 
            int x1 = 0, y1 = 0; //左上角坐标 
            int x2 = n-1, y2 = m-1; //右下角坐标 
            // 这两个坐标表示了一个矩形(最开始的矩阵)
            // 然后按照要求打印最外圈的数据. 
            // 打印完毕之后, 缩小矩形的大小.
            while(x1 <= x2 && y1 <= y2)
            {
                for(int j = y1; j <= y2; ++j)
                    ret.push_back(mat[x1][j]);
                for(int i = x1+1; i < x2; ++i) 
                    ret.push_back(mat[i][y2]); 
                for(int j = y2; x1 < x2 && j >= y1; --j) //x1 < x2：只有在不是单一的横行时才执行这个循环
                    ret.push_back(mat[x2][j]); 
                for(int i = x2-1; y1 < y2 && i > x1; --i)//y1 < y2：只有在不是单一的竖列时才执行这个循环
                    ret.push_back(mat[i][y1]);
                x1++; y1++;
                x2--; y2--; 
            }
            return ret;
        }
};
