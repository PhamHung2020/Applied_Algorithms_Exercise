#include <iostream>

using namespace std;

int n, k;
int a[10100];

double solve(int start, int end)
{
    if (end - start == k - 1)
    {
        double sum = 0;
        for (int i = start; i <= end; ++i)
            sum += a[i];
        return sum / k;
    }

    int mid = (start + end) / 2;
    int left = -1e9, right = -1e9;
    if (mid - left >= k - 1)
        left = solve(start, mid);
    if (end - mid >= k)
        right = solve(mid + 1, end);

    double average = 0;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    return 0;
}