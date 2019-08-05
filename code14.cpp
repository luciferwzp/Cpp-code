//对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。 
//给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。 
//测试样例： "(()())",6
//返回：true 
//测试样例： "()a()()",7 
//返回：false 
//测试样例： "()(()()",7 
//返回：false
//




/*方法一
class Parenthesis {
    public:
        bool chkParenthesis(string A, int n) {
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (A[i] == '(')
                {
                    count += 1;

                }
                if (A[i] == ')')
                {
                    count -= 1;

                }
                if (A[i] == ')' && A[i] == '(')
                {
                    return false;
                    break;

                }
            }
            if (count == 0)
            {
                return true;

            }
            else
                return false;
        }
};
*/



class Parenthesis
{ 
    public: 
        bool chkParenthesis(string A, int n) 
        { 
            // write code here
            stack<char> sc; 
            for(auto ele : A)
            { 
                switch(ele) 
                {
                    case '(':
                        sc.push(ele);
                        break; 
                    case ')': 
                        { 
                            if(sc.empty() || sc.top() != '(') 
                                return false; 
                            elsesc.pop(); 
                        }break; 
                    default: 
                        return false;
                } 
            }
            return true;
        }
};
