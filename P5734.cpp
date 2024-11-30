#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    string str;
    cin >> str;
    int operafun;
    for (int i = 0; i < q; i++)
    {
        cin >> operafun;
        switch (operafun)
        {
        case 1:
        {
            string toaddstr;
            cin >> toaddstr;
            str += toaddstr;
            cout << str << endl;
            break;
        }
        case 2:
        {
            int a, b;
            cin >> a >> b;
            str = str.substr(a, b);
            cout << str << endl;
            break;
        }
        case 3:
        {
            int a;
            string toinsertstr;
            cin >> a >> toinsertstr;
            str.insert(a, toinsertstr);
            cout << str << endl;
            break;
        }
        case 4:
        {
            string substr;
            cin >> substr;
            size_t pos = str.find(substr);
            if (pos != string::npos)
            {
                cout << pos << endl;
            }
            else
            {
                cout << -1 << endl;
            }
            break;
        }
        }
    }
}