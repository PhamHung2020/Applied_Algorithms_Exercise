#include <iostream>
#include <vector>

using namespace std;

int n, k;
int numPoint;
int dist[30][30];
int isVisited[30];
int numPassengers = 0;
int minRoute = 1e9;
int minDist = 1e9;

bool check(int point, int nextPoint)
{
    if (isVisited[nextPoint])
        return false;

    if (!dist[point][nextPoint])
        return false;

    if (nextPoint <= n)
    {
        if (numPassengers >= k)
            return false;
    }
    else
    {
        if (!isVisited[nextPoint - n])
            return false;
    }
    return true;
}

void Try(int point, int lengthRoute, int numPointVisit)
{
    if (numPointVisit > numPoint)
    {
        if (dist[point][0])
            minRoute = min(minRoute, lengthRoute + dist[point][0]);
        return;
    }

    int totalMinDist = minDist * (numPoint - numPointVisit + 1);
    for (int i = 1; i <= numPoint; ++i)
    {
        if (check(point, i) && lengthRoute + totalMinDist + dist[point][i] < minRoute)
        {
            isVisited[i] = true;
            if (i <= n)
                numPassengers++;
            else
                numPassengers--;
            Try(i, lengthRoute + dist[point][i], numPointVisit + 1);
            isVisited[i] = false;
            if (i <= n)
                numPassengers--;
            else
                numPassengers++;
        }
    }
}

int main()
{
    cin >> n >> k;
    numPoint = 2 * n;
    for (int i = 0; i <= numPoint; ++i)
    {
        for (int j = 0; j <= numPoint; ++j)
        {
            cin >> dist[i][j];
            if (i != j && dist[i][j] < minDist)
                minDist = dist[i][j];
        }
    }

    Try(0, 0, 1);
    cout << minRoute;
    return 0;
}