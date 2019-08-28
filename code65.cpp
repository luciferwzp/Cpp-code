//一块花布条，里面有些图案，另有一块直接可用的小饰条，里面也有一些图案。
//对于给定的花布条和小饰条，计算一下能从花布条中尽可能剪出几块小饰条来呢？
//输入描述： 输入包含多组数据。 每组数据包含两个字符串s,t，分别是成对出现的花布条和小饰条，
//其布条都是用可见ASCII字符表示的，可见的ASCII字符有多少个，布条的花纹也有多少种花样。花纹条和小饰条不会超过1000个字符长。
//输出描述： 对应每组输入，输出能从花纹布中剪出的最多小饰条个数，如果一块都没有，那就输出0，每个结果占一行。 
//示例1: 输入
//abcde a3 
//aaaaaa aa 
//输出
//0
//3


//【解题思路】：
//C语言可以通过strstr函数找，用STL的string库可以通过find函数找，找到以后跳过一个T串的长度。
//例如：在abcacbcbcabscbc中找cbc，第一次找到了这个位置：abcacbcbcabscbc，
//找到这个下标后，会跳过整体cbc，也就是从这个位置继续找：abcacbcbcabscbc，否则如果你只跳一个字符，会导致cbcbc会被算成2次，
//而按照本题的题意，应该算一次。


#include<iostream> 
#include<string>
int main()
{
    std::string s, t;
    while(std::cin >> s >> t)
    {
        int res = 0;
        size_t pos = 0;
        //依次在 s 中查找 t 即可，直到再也找不到 t
        while((pos = s.find(t, pos)) != std::string::npos) 
        {
            pos += t.size(); //跳过t串整体的长度 
            ++res; //计数 
        }
        std::cout << res << std::endl; 
    }
    return 0;
}
