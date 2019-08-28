//NowCoder在淘宝上开了一家网店。
//他发现在月份为素数的时候，当月每天能赚1元；否则每天能赚2元。
//现在给你一段时间区间，请你帮他计算总收益有多少。
//输入描述： 输入包含多组数据。 每组数据包含两个日期from和to (2000-01-01 ≤ from ≤ to ≤ 2999-12-31
//)。 日期用三个正整数表示，用空格隔开：year month day。
//输出描述： 对应每一组数据，输出在给定的日期范围（包含开始和结束日期）内能赚多少钱。
//示例1: 
//输入
//2000 1 1    2000 1 31
//2000 2 1    2000 2 29 
//输出
//62
//29


//【解题思路】：
//既然是一个变相的日期计算器，那就写一个日期计算器，然后加以修改即可。那么，日期计算器怎么写呢？
//日期计算器的话，我们将会把日期计算分为三个部分：第一个不足一年的年份，最后一个不足一年的年份，和中间的足年年份。
//足年年份我们只需要判断闰年后加365或366就行了。不足年，我们就要求出这个日期是这一年的第几天。
//假设要求的是1994年5月27日到2003年4月29日，那么，我们就要先求出5月27日是这一年的第几天，然后判断1994年不是闰年，
//不是，所以用365减去这个天数，就得到结果了。本题中第一天也要算，所以还要加上这一天。
//然后再算出4月29日是2003年的第几天，就可以解决问题了。所以，我们需要一个函数，功能是给出一个年月日，求出这是这一年的第几天。
//这些功能全部实现后，再去改造使得1、4、6、8、9、10、12月的天数翻倍，那么程序就全部完成了。


#include<cstdio>
#include<cmath>
#include<iostream>
//闰年判断函数 
inline int leap_year(int year) 
{
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

//足年天数
inline int profit_of_year(int year)
{
    return 2 * 31 + 1 * 28 + 
        1 * 31 + 2 * 30 +
        1 * 31 + 2 * 30 + 
        1 * 31 + 2 * 31 + 
        2 * 30 + 2 * 31 +
        1 * 30 + 2 * 31 +
        leap_year(year);
}

//判断这个月份是不是质数月 
inline bool prime(int n)
{
    return n == 2 || n == 3 || n == 5 || n == 7 || n == 11;
}

//求出一个日子是这一年的第几天 
int profit_of_this_year(int year, int month, int day)
{
    if(!prime(month)) 
    {
        day *= 2;
    }
    while(--month)
    {
        switch(month)
        {
            case 1:
            case 8: 
            case 10: 
            case 12: day += 62; 
                     break;
            case 3: 
            case 5: 
            case 7: day += 31;
                    break;
            case 4: 
            case 6: 
            case 9: day += 60;
                    break;
            case 11:
                    day += 30;
                    break;
            case 2: day += 28 + leap_year(year);
                    break;
            default:;
        }
    }
    return day;
}
int main()
{ 
    int year1,month1, day1, year2, month2, day2;
    int count_profit = 0;
    while(std::cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2) 
    {
        count_profit = 0;
        count_profit += profit_of_year(year1) - profit_of_this_year(year1, month1, day1 - 1);
        //这里的day1 - 1虽然有可能会出现0日，但是实际2月0日就相当于1月31日，所以不影响结果。
        count_profit += profit_of_this_year(year2, month2, day2); 
        if(year1 == year2) //避免起点和终点是同一年，如果是同一年，要减掉这一年的天数。
        {
            count_profit -= profit_of_year(year1);
        }
        for(int i = year1 + 1; i < year2; i++)//中间足年每一年的天数
        {
            count_profit += profit_of_year(i); 
        }
        std::cout << count_profit << std::endl;
    }
    return 0;
}

