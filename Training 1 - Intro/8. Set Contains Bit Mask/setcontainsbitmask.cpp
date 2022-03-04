#include <iostream>

int main()
{
    int n, m, a[32], b[32];
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    std::cin >> m;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> b[i];
    }

    for (int i = 0; i < m; ++i)
    {
        bool c = false;
        for (int j = 0; j < n; ++j)
            if (a[j] == b[i])
            {
                c = true;
                break;
            }
        if (!c)
        {
            std::cout << 0;
            return 0;
        }
    }
    std::cout << 1;
    return 0;
}