//反三角
//输入行数必须为基数，否则报错。三角的角只有一个“* ”，随后每增加一行就比上一行多两个“* ”

#include<iostream>
using namespace std;
int main()
{
    int m;
    cout << "请输入行数:" << endl;
    cin >> m;
    int n = (m / 2);
    if (m % 2 == 0)
    {
        cout << "error" << endl;

    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                cout << " ";

            }

            for (int k = 0; k < m - 2 * i; k++)
            {
                cout << "*";

            }
            cout << endl;

        }
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m - n - 1 - i; j++)
            {
                cout << " ";

            }

            for (int k = 0; k < 2 * i + 1; k++)
            {
                cout << "*";

            }
            cout << endl;

        }

    }
    system("pause");
    return 0;

}

