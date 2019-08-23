//春节期间小明使用微信收到很多个红包，非常开心。
//在查看领取红包记录时发现，某个红包金额出现的次数超过了红包总数的一半。
//请帮小明找到该红包金额。写出具体算法思路和代码实现，要求算法尽可能高效。
//给定一个红包的金额数组gifts及它的大小n，请返回所求红包的金额。 
//若没有金额超过总数的一半，返回0。
//测试样例： [1,2,3,2,2],5
//返回：2


//【解题思路】：
//本题两种思路，第一种排序思路，如果一个数出现次数超过一半了，排序过后，必然排在中间，则最后遍历
//整个数组查看是否符合即可。第二种思路可以用map统计每个数字出现的次数，最后判断有没有超过一半的数字。


class Gift
{ 
    public:
        int getValue(vector<int> gifts, int n)
        {
            sort(gifts.begin(), gifts.end()); 
            //超过一半的数排序之后必然排在中间 
            int middle = gifts[n / 2];
            int count = 0;
            for(int i = 0; i < n; i++)
            {
                //统计排在中间的数的个数 
                if(gifts[i] == middle)
                {
                    count++;
                } 
            }
            //如果个数大于一半，则存在超过一半的数
            if(count > n / 2)
                return middle;
            elsereturn 0;
        }
};


/*思路二：map统计*/ 
class Gift 
{
    public: int getValue(vector<int> gifts, int n)
            {
                map<int,int> count;
                int middle = gifts.size() / 2;
                for(const auto& e : gifts)
                {
                    ++count[e];
                }
                for(const auto& e : count)
                {
                    if(e.second >= middle)
                        return e.first;
                }
                return 0; 
            }
};
