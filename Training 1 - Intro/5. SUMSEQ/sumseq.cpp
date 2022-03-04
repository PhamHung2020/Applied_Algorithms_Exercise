#include <iostream>

int main()
{
    unsigned long long CONST = 1000000000 + 7;
    unsigned long long sum = 0;
    int n, a;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a;
        sum += a;
    }
    std::cout << sum % CONST;
    return 0;
}