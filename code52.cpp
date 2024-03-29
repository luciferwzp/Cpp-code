//小喵们很喜欢把自己装进容器里的（例如碗），但是要是碗的周长比喵的身长还短，它们就进不去了。 
//现在告诉你它们的身长，和碗的半径，请判断一下能否到碗里去。
//输入描述： 输入有多组数据。 每组数据包含两个整数n (1≤n≤2^128) 和r (1≤r≤2^128)，分别代表喵的身长和碗的半径。 圆周率使用3.14。
//输出描述： 对应每一组数据，如果喵能装进碗里就输出“Yes”；否则输出“No
//”。 示例1: 输入6 1
//7 1
//9876543210   1234567890
//输出Yes 
//No
//No


//【解题思路】：通过输入碗半径计算得到周长，与输入的猫的身长相比较

#include<iostream>
using namespace std;
int main()
{
    double n,r; 
    while(cin >> n >> r)
    {
        //周长：2*r*3.1415
        //身长：n 
        if(n > (2*r*3.1415)) 
            cout << "No" << endl; 
        else
            cout << "Yes" << endl;
    }
    return 0;
}
