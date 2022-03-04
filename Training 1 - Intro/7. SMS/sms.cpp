#include <iostream>
#include <string>

int arr[27] = {0, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

int main()
{
    int n, sum, length;
    std::string s;
    std::cin >> n;
    getchar();
    for (int i = 1; i <= n; ++i)
    {
        getline(std::cin, s);
        sum = 0;
        length = s.length();
        for (int j = 0; j < length; ++j)
        {
            if (s[j] == ' ')
                sum += 1;
            else
                sum += arr[s[j] - 96];
        }
        std::cout << "Case #" << i << ": " << sum << '\n';
    }
    return 0;
}