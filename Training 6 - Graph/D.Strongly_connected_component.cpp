#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, curnum, res;
vector<int> adjList[100005];
int isConnect[100005], low[100005], num[100005];
stack<int> iCom;

void Scc(int u)
{
    low[u] = num[u] = ++curnum;
    isConnect[u] = 1;
    iCom.push(u);

    for (const int& v : adjList[u])
    {
        if (num[v] == -1)
        {
            Scc(v);
            low[u] = min(low[u], low[v]);
        }
        else if (isConnect[v] == 1)
        {
            low[u] = min(low[u], num[v]);
        }
    }

    if (low[u] == num[u])
    {
        ++res;
        while (!iCom.empty())
        {
            int cur = iCom.top();
            isConnect[cur] = 0;
            iCom.pop();
            if (cur == u)
                break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
    }
    memset(low, -1, sizeof(low));
    memset(num, -1, sizeof(num));

    for (int i = 1; i <= n; ++i)
    {
        if (num[i] == -1)
            Scc(i);
    }

    cout << res;
    return 0;
}