//写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。


//【解题思路】：数字的相加可以转换为二进制的加法，注意每一位相加与进位即可
//1. 两个数异或：相当于每一位相加，而不考虑进位；


class Solution 
{
    public:
        int Add(int num1,int num2) 
        {
            while(num2 != 0)
            { 
                int sum = num1 ^ num2;//得到相加后不包含进位的数据 
                int carray = (num1 & num2) << 1; //得到两数相加的进位 
                num1 = sum; //两个结果相加，直到进位为0 
                num2 = carray;
            }
            return num1; 
        }
};
