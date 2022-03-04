#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n;
int p[100100];
stack<int> st;
queue<int> q;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("./test-DINO/Test0/DINO.inp", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p[i];

    for (int i = n - 1; i >= 0; --i)
        st.push(p[i]);

    cin.ignore();
    getline(cin, s);
    int length = s.length();
    for (int i = 0; i < length; ++i)
    {
        if (s[i] == 'C' && !st.empty())
        {
            int top = st.top();
            q.push(top);
            st.pop();
        }
        else if (!q.empty())
        {
            int front = q.front();
            st.push(front);
            q.pop();
        }
    }

    while (!st.empty())
    {
        cout << st.top() << ' ';
        st.pop();
    }

    return 0;
}