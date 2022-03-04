#include <iostream>
#include <string>

int main()
{
    int n;
    std::cin >> n;
    getchar();
    for (int i = 0; i < n; ++i)
    {
        std::string s;
        getline(std::cin, s);
        int length = s.length();
        if (length > 10)
            std::cout << s[0] << length - 2 << s[length - 1] << '\n';
        else
            std::cout << s << '\n';
    }
    return 0;
}