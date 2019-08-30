//标题：Pre-Post
//输入描述： Input will consist of multiple problem instances. Each instance will consist of a line of the form m s1 s2, indicating that the trees are m-ary trees, s1 is the pre-order traversal and s2 is the post-order traversal.All traversal strings will consist of lowercase alphabetic characters. For all input instances, 1 <= m <= 20 and the length of s1 and s2 will be between 1 and 26 inclusive. If the length of s1 is k (which is the same as the length of s2, of course), the first k letters of the alphabet will be used in the strings. An input line of 0 will terminate the input. 

//输出描述： For each problem instance, you should output one line containing the number of possible trees which would result in the pre-order and post-order traversals for the instance. All output values will be within the range of a 32-bit signed integer.
//For each problem instance, you are guaranteed that there is at least one tree with the given pre-order and post-order traversals. 
//示例1: 输入
//2 abc cba
//2 abc bca 
//10 abc bca 
//13 abejkcfghid jkebfghicda 
//输出
//4
//1
//45
//207352860 


#include<string> 
#include<tuple> 
#include<list>
#include<cstdio> 
// 求n的阶乘 
long long factorial(int n)
{
    long long r = 1;
    for(int i = 1; i <= n; i++)
    {
        r *= i;  
    }
    return r; 
}
// 求 n, m 的组合 C(n, m)
// 利用 C(n, m) == C(n, n - m) 的特点，计算容易的 
long long combination(int n, int m)
{
    int max = m > (n - m) ? m : (n - m);
    long long numerator = 1;
    for(int i = max + 1;i <= n;i++)
    {
        numerator *= i; 
    }
    return numerator / factorial(n - max);
}
// 重命名类型，类似于 typedef 作用
using PrePost = std::tuple<std::string, std::string>;
// 给出一棵树的前序+后序，利用最上面注释的原理
// 把每棵子树的前序+后序切分出来
std::list<PrePost> splitSubTrees(std::string const& pre, std::string const& post) 
{
    std::list<PrePost> list{};
    size_t preIdx = 1; 
    size_t lastPost = 0;
    while(preIdx < pre.size()) 
    {
        char rootValue = pre[preIdx];
        size_t postIdx = post.find(rootValue);
        int countOfNode = postIdx - lastPost + 1; 
        list.emplace_back(std::make_tuple( pre.substr(preIdx, countOfNode), post.substr(lastPost, countOfNode));
                preIdx += countOfNode;
                lastPost += countOfNode;
                }
                return list;
                }
                // 递归的求解每一层的可能性，直到树中只剩一个或者零个结点
                long long calculateNumOfPossibilities(int m, std::string const& pre, std::string const& post) 
                {
                if(pre.size() == 0 || pre.size() == 1)
                {
                return 1;
                }
                std::list<PrePost> subTrees = splitSubTrees(pre, post);
                long long result = combination(m, subTrees.size());
                for(PrePost const& prePost : subTrees)
                {
                result *= calculateNumOfPossibilities(m,std::get<0>(prePost), std::get<1>(prePost));
                }
                return result;
                }
int main() 
{
    int m; 
    char pre[30];
    char post[30];
    while(scanf("%d %s %s", &m, pre, post) != EOF)
    {
        printf("%lld\n", calculateNumOfPossibilities(m, pre, post)); 
    }
    return 0;  
}
