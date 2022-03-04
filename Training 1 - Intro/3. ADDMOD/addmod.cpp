#include <iostream>

unsigned long long CONST = 1000000000 + 7;

int main()
{
    unsigned long long a, b;
    std::cin >> a >> b;
    a = a % CONST;
    b = b % CONST;
    std::cout << (a + b) % CONST;

    return 0;
}