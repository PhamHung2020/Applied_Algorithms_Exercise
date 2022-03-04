#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, q;
int d[15];
bool isVisited[15];
int countRoute = 0;
int minDistance = 1e9;
int startPos[15];
int c[15][15];

void Try(int numD, int numRoute, int numClient, int distance, int previousClient)
{
    if (numClient == n && numRoute == k)
    {
        if (distance + c[previousClient][0] < minDistance)
            minDistance = distance + c[previousClient][0];
        return;
    }

    if (numRoute > k)
        return;
    else if (numClient == n)
        return;

    if (numD == 0)
    {
        for (int i = startPos[numRoute - 1] + 1; i <= n; ++i)
        {
            if (!isVisited[i] && d[i] <= q)
            {
                isVisited[i] = true;
                startPos[numRoute] = i;
                Try(d[i], numRoute, numClient + 1, distance + c[0][i], i);
                isVisited[i] = false;
            }
        }
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!isVisited[i])
        {
            if (numD + d[i] <= q)
            {
                isVisited[i] = true;
                Try(numD + d[i], numRoute, numClient + 1, distance + c[previousClient][i], i);
                isVisited[i] = false;
            }
        }
    }
    Try(0, numRoute + 1, numClient, distance + c[previousClient][0], 0);
}

int main()
{
    cin >> n >> k >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> d[i];
    }

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            cin >> c[i][j];
        }
    }
    startPos[0] = 0;
    Try(0, 1, 0, 0, 0);
    cout << minDistance;
    return 0;
}