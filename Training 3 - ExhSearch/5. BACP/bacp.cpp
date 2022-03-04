#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int c[20];
int a[20][20];
int loadOfPeriod[10];
int courses[20];
int loadMax = 0;
int loadMin = 1e9;

bool checkCourse(int course, int period)
{
    for (int i = 0; i < n; ++i)
        if (a[i][course] && courses[i] >= period)
            return false;

    for (int i = 0; i < n; ++i)
        if (a[course][i] && courses[i] && period >= courses[i])
            return false;
    return true;
}

void Try(int course)
{
    for (int i = 1; i <= m; ++i)
    {
        if (checkCourse(course, i))
        {
            courses[course] = i;
            loadOfPeriod[i] += c[course];
            int pre = loadMax;
            loadMax = max(loadMax, loadOfPeriod[i]);

            if (course == n)
                loadMin = min(loadMin, loadMax);
            else if (loadMax < loadMin)
                Try(course + 1);

            loadOfPeriod[i] -= c[course];
            loadMax = pre;
            courses[course] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    Try(0);
    cout << loadMin;
    return 0;
}