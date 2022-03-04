#include <iostream>

unsigned long long maxArea(int n)
{
    unsigned long long a[1000010];
    int left[1000010];
    left[0] = 0;
    int right[1000010];
    right[n - 1] = n - 1;
    unsigned long long max = 0, area;

    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    for (int i = 1; i < n; ++i)
    {
        int j = i - 1;
        while (j >= 0 && a[j] >= a[i])
            j = left[j] - 1;
        left[i] = j + 1;
    }

    for (int i = n - 2; i >= 0; --i)
    {
        int j = i + 1;
        while (j < n && a[j] >= a[i])
            j = right[j] + 1;
        right[i] = j - 1;
    }

    for (int i = 0; i < n; ++i)
    {
        area = (right[i] - left[i] + 1) * a[i];
        if (area > max)
            max = area;
    }

    return max;
}

int main()
{
    int n;
    std::cin >> n;

    while (n != 0)
    {
        std::cout << maxArea(n) << '\n';
        std::cin >> n;
    }
    return 0;
}