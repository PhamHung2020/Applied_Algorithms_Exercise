#include <iostream>
#include <vector>

using namespace std;

int n, m, k, res;
vector<int> adjList[35];
int isVisited[35], previous[35];

void Try(int x)
{
    if(x == k + 2)
    {
        ++res;
        return;
    }

    int u = previous[x-1];
    for(int i = 0; i < adjList[u].size(); ++i)
    {
        int v = adjList[u][i];
        if(!isVisited[v])
        {
            previous[x] = v;
            isVisited[v] = 1;
            Try(x+1);
            isVisited[v] = 0;
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> m;
    for(int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for(int i = 1; i <=n ;++i)
        adjList[0].push_back(i);

    Try(1);
    cout << res / 2;
    return 0;
}
