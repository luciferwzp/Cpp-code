//输入
//abc
//123456789
//输出
//abc00000
//12345678
//90000000

//方法一
#include <iostream> 
using namespace std;
int main(){
    string str;

    while(getline(cin,str)){
        while(str.size()>8){
            cout << str.substr(0,8) <<endl;
            str=str.substr(8);                                        
        }
        cout << str.append(8-str.size(),'0') << endl;   //不够8位的补0
    }
}


//方法二

void fuck(string str) {
    if (str == "")
        return;
    if (str.size() <= 8) {
        str.append(8 - str.size(), '0');
        cout << str << endl;
        return;
    }
    cout << str.substr(0, 8) << endl;
    fuck(str.substr(8, str.size()));
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    fuck(str1);
    fuck(str2);
    return 0;
}
