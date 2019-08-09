//任意一个偶数（大于2）都可以由2个素数组成，
//组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对 
//输入描述： 输入一个偶数 
//输出描述： 输出两个素数 
//示例1: 输入20
//输出713


//本题首先需要判断素数，素数表示除过1和本身，不能被其它数整除。通过循环遍历来判断一个数是否为素数。
//最近的两个素数应该从最中间的位置开始向两边查找


#include<iostream>
#include<algorithm> 
using namespace std; //判断素数
bool isPrime(int num) 
{ 
    int tmp = sqrt(num); 
    //只遍历到开方出，不能被开方左边的数整除，则一定不能被开方右边的数整除 
    for(int i = 2; i <= tmp; i++) 
    {
        if(num %i == 0) 
            return false;
    }
    return true;
}
int main()
{ 
    int num; 
    int half;
    int i; 
    while(cin >> num)
    {
        half = num / 2;
        //从中间向两边找 
        for (i = half; i > 0; i--)
        {
            if (isPrime(i) && isPrime(num - i)) 
                break;
        }
        cout << i << endl << num - i << endl;  
    }
    return 0; 
}
