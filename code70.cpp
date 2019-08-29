//NowCoder每天要处理许多邮件，但他并不是在收件人列表中，有时候只是被抄送。
//他认为这些抄送的邮件 重要性比自己在收件人列表里的邮件低，因此他要过滤掉这些次要的邮件，优先处理重要的邮件。 
//现在给你一串抄送列表，请你判断目标用户是否在抄送列表中。
//输入描述： 输入有多组数据，每组数据有两行。 第一行抄送列表，姓名之间用一个逗号隔开。
//如果姓名中包含空格或逗号，则姓名包含在双引号里。总长度不超过512个字符。
//第二行只包含一个姓名，是待查找的用户的名字（姓名要完全匹配）。长度不超过16个字符。
//输出描述： 如果第二行的名字出现在收件人列表中，则输出“Ignore”，表示这封邮件不重要；
//否则，输出“Important!”， 表示这封邮件需要被优先处理。
//示例1:
//输入
//Joe,Kewell,Leon
//Joe
//"Letendre, Bruce",Joe,"Quan, William" 
//William
//输出
//Ignore
//Important!


//【解题思路】： 本题最简单的思路，就是把第一行中的每一个人名都存在一个string容器里，然后和第二行的这个字符串一个一个比过去，
//看有没有重合的即可。比较简单的思路是可以做一个string的数组，分割完了一比就行了。
//例如我下文中使用 的是比较基础的vector。
//当然也可以选择一些其他的更方便的容器。需要注意的点是双引号需要特殊处理，别的都是 正常的字符串处理。


#include<iostream>
#include<cstdio> 
#include<vector>
#include<algorithm> 
#include<string> 
int main()
{
    std::string line; 
    while(std::getline(std::cin, line)) //第一次的输入抓到line里
    {
        std::vector<std::string> names; //names里存放所有的数据 
        size_t pos = 0;
        while (pos < line.length()) //位置如果大于等于了长度，那么证明找完了，双引号的情况从这里跳出 
        {
            if (line[pos] == '\"') //找到双引号要处理双引号内部 
            {
                size_t end = line.find("\"", pos + 1); 
                names.push_back(line.substr(pos + 1, end - pos - 1)); //截取出来放到names里
                pos = end + 2;//跳掉后面的双引号和逗号 
            }
            else
            {
                size_t end = line.find(",", pos + 1);
                if(end == -1) //找不到逗号证明这是最后一个字符串了，直接存了这个字符串后跳出
                {
                    names.push_back(line.substr(pos, line.size() - pos));
                    break;
                }
                names.push_back(line.substr(pos, end - pos)); 
                pos = end + 1; //跳掉后面的逗号  
            }
        }
        std::getline(std::cin, line); 
        if (names.end() == std::find(names.begin(), names.end(), line))
            //std::find函数是在两个迭代器中间查找，最后一个参数是要找的值。 
            //找到了返回对应迭代器，找不到就返回区间末尾的位置。本例中是end()。
        {
            printf("Important!\n"); //没找到 
        }
        else 
        {
            printf("Ignore\n"); //找到了  
        }
    }
    return 0;
}
