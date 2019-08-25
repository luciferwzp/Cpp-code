//给定一个长度不小于2的数组arr。
//写一个函数调整arr，使arr中要么所有的偶数位上都是偶数，要么所有的奇数位上都是奇数上。 
//要求：如果数组长度为N，时间复杂度请达到O(N)，额外空间复杂度请达到O(1),下标 0,2,4,6...算作偶数位,下标1,3,5,7...算作奇数位，
//例如[1,2,3,4]调整为[2,1,4,3]即可


//【解题思路】：在偶数位上寻找非偶数，在奇数位上寻找非奇数，两个数字进行位置互换即可


class Solution
{
    public:
        void oddInOddEvenInEven(std::vector<int>& arr, int len)
        {
            long i = 0, j = 1;
            while(i < len && j < len)
            {
                if((arr[i] % 2) == 0)
                {
                    i += 2;
                    continue;
                }
                //偶数位上寻找非偶数 
                if((arr[j] % 2) != 0)
                {
                    j += 2; 
                    continue;
                }
                //奇数位上寻找非奇数 
                swap(arr[i], arr[j]);
            }
        }
};
