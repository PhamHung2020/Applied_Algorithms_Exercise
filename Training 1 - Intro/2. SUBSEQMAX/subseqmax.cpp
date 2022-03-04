#include <iostream>
#include <algorithm>
#include <limits>

int main()
{
    int n, a, maxWeight = -1e9, weight;
    std::cin >> n;
    weight = maxWeight;
    for (int i = 1; i < n; ++i)
    {
        std::cin >> a;
        weight = std::max(a, weight + a);
        maxWeight = std::max(maxWeight, weight);
    }
    std::cout << maxWeight;
    return 0;
}