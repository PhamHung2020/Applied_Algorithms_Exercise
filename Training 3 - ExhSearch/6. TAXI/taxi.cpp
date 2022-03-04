#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int numPoint;
int distances[30][30];
int minRoute = 2147483647;
bool isVisited[15];

void Try(int point, int lengthRoute, int numPointVisited)
{
    if (numPointVisited == n + 1 && distances[point][0])
    {
        minRoute = min(minRoute, lengthRoute + distances[point][0]);
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (distances[point][i] && !isVisited[i])
        {
            int length = lengthRoute + distances[point][i] + distances[i][i + n];
            if (length < minRoute)
            {
                isVisited[i] = true;
                Try(i + n, length, numPointVisited + 1);
                isVisited[i] = false;
            }
        }
    }
}

int main()
{
    cin >> n;

    numPoint = 2 * n + 1;
    int temp;
    for (int i = 0; i < numPoint; ++i)
    {
        for (int j = 0; j < numPoint; ++j)
        {
            cin >> distances[i][j];
        }
    }
    Try(0, 0, 1);
    cout << minRoute;
    return 0;
}