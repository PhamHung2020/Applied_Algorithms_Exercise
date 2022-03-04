#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 100000;
int a[MAX];
int min[MAX];

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    min[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i)
    {
        if (a[min[i + 1]] > a[i])
            min[i] = i;
        else
            min[i] = min[i + 1];
    }

    for (int i = 0; i < n; ++i)
    {
        int pos = i;
        while (pos < n - 1 && a[min[pos + 1]] < a[i])
        {
            pos = min[pos + 1];
        }
        std::cout << pos - i - 1 << ' ';
    }
    return 0;
}