#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, q;
int d[15];
bool isVisited[15];
int countRoute = 0;
int minD = 1e9;
int startPos[15];

void Try(int numD, int numRoute, int numClient)
{
    if (numClient == n && numRoute == k)
    {
        ++countRoute;
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
                Try(d[i], numRoute, numClient + 1);
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
                Try(numD + d[i], numRoute, numClient + 1);
                isVisited[i] = false;
            }
        }
    }
    Try(0, numRoute + 1, numClient);
}

int main()
{
    cin >> n >> k >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> d[i];
    }
    startPos[0] = 0;
    Try(0, 1, 0);
    cout << countRoute;
    return 0;
}