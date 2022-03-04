#include <iostream>

int main()
{
    unsigned long long CONST = 1000000000 + 7;
    unsigned long long a, b, p = 1;
    std::cin >> a >> b;
    a = a % CONST;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            p = (p * a) % CONST;
        }
        b >>= 1;
        a = (a * a) % CONST;
    }
    std::cout << p;
    return 0;
}