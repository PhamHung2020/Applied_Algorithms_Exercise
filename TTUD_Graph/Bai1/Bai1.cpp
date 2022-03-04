#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int n, k;
pair<int, int> xy[550];
bool visited[550];
bool isOk = false;

int dist(int i, int j)
{
    int x1 = xy[i].first;
    int x2 = xy[j].first;
    int y1 = xy[i].second;
    int y2 = xy[j].second;
    return (int)sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void check(int u)
{
    visited[u] = true;
    for (int i = 2; i <= n; ++i)
    {
        if (isOk)
            return;
        if (!visited[i] && dist(u, i) <= k)
        {
            if (i == n)
            {
                isOk = true;
                return;
            }
            check(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> xy[i].first >> xy[i].second;
    }
    check(1);
    if (isOk)
        cout << "YES";
    else
        cout << "NO";
    return 0;

}