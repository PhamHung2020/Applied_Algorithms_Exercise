#include <iostream>

int main()
{
    unsigned long long a, b, a1, b1, a0, b0, c1, c0;
    std::cin >> a >> b;
    a1 = a / 10;
    b1 = b / 10;

    a0 = a % 10;
    b0 = b % 10;

    c1 = a1 + b1 + (a0 + b0) / 10;
    c0 = (a0 + b0) % 10;

    if (c1 == 0)
        std::cout << c0;
    else
        std::cout << c1 << c0;
    return 0;
}