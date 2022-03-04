#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point
{
    long long x, y;
    int id;
};

Point a[50100];
double res;
int p1, p2;

bool cmp_x(Point a, Point b)
{
    return a.x < b.x;
}

bool cmp_y(Point a, Point b)
{
    return a.y < b.y;
}

double distance(Point a, Point b)
{
    return sqrt((double)(a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void update(Point a, Point b)
{
    double x = distance(a, b);
    if (x < res)
    {
        p1 = a.id;
        p2 = b.id;
        res = x;
    }
}

void closest(int l, int r)
{
    if (l >= r)
        return;
    if (l + 1 == r)
    {
        update(a[l], a[r]);
        return;
    }

    int mid = (l + r) / 2;
    int mid_x = a[mid].x;

    closest(l, mid);
    closest(mid + 1, r);

    vector<Point> v;
    for (int i = l; i <= r; ++i)
    {
        if (abs(a[i].x - mid_x) <= res)
            v.push_back(a[i]);
    }
    sort(v.begin(), v.end(), cmp_y);
    double temp = res;
    for (int i = 0; i < v.size(); ++i)
    {
        int j = i + 1;
        while (j < v.size() && v[j].y - v[i].y <= temp)
        {
            update(v[i], v[j]);
            ++j;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }

    sort(a, a + n, cmp_x);
    res = 1e9;
    closest(0, n - 1);
    printf("%d %d %.6f", min(p1, p2), max(p1, p2), res);
    return 0;
}