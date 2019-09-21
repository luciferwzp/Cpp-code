/*解法一：在原字符串上修改
 * “abcdef”循环左移9位（3位）
 * 前3位逆序，后3位逆序，整体再逆序。
 * “cbafed”-> “defabc”
 * */
class Solution {
    public:
        string LeftRotateString(string str, int n) {
            int len = str.size();
            if(len <= 0)
                return "";
            n = n%len;
            if(n==0)
                return str;
            reverseStr(str,0,n-1);
            reverseStr(str,n,len-1);
            reverseStr(str,0,len-1);
            return str;
        }
        void reverseStr(string &str, int left, int right)
        {
            for(int i=left,r=right;i<=left+(right-left)/2;++i){
                swap(str[i],str[r--]);
            }
        }
};
/*解法二：
 * 借助n个大小的额外空间
 * */class Solution {
     public:
         string LeftRotateString(string str, intn) {
             string ret;
             intlen = str.size();
             if(len <= 0)
                 return"";
            
             n = n%len;
             ret = str+str.substr(0,n);
             ret = ret.substr(n,str.size());
             return ret;
         }
 };
