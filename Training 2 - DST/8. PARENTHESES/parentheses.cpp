#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool parenthese(const string &str)
{
    stack<char> st;
    st.push(str[0]);
    int length = (int)str.length();
    for (size_t j = 1; j < length; ++j)
    {
        if (str[j] == '(' || str[j] == '[' || str[j] == '{')
            st.push(str[j]);
        else
        {

            if (!st.empty() && ((str[j] == ')' && st.top() == '(') ||
                                (str[j] == ']' && st.top() == '[') ||
                                (str[j] == '}' && st.top() == '{')))
                st.pop();
            else
            {
                return false;
            }
        }
    }

    return st.empty();
}

int main()
{
    int n;
    cin >> n;

    getchar();
    for (int i = 0; i < n; ++i)
    {
        string str;
        getline(cin, str);
        cout << parenthese(str) << '\n';
    }
    return 0;
}