#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;
const int MAX = 2500;

int m[MAX][MAX];
int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int i = 0; i < MAX; ++i)
            for (int j = 0; j < MAX; ++j)
                m[i][j] = 0;

        int l, c;
        std::cin >> l >> c;

        int temp;
        vector<pair<int, int>> p1;
        vector<pair<int, int>> p2;
        for (int i = 0; i < l; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                std::cin >> temp;
                if (temp)
                    p1.push_back({i, j});
            }
        }

        for (int i = 0; i < l; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                std::cin >> temp;
                if (temp)
                    p2.push_back({i, j});
            }
        }

        int length1 = (int)p1.size();
        int length2 = (int)p2.size();

        int result = 0;
        for (int i = 0; i < length1; ++i)
        {
            for (int j = 0; j < length2; ++j)
            {
                int a = ++m[p2[j].first - p1[i].first + 1005][p2[j].second - p1[i].second + 1005];
                result = std::max(a, result);
            }
        }

        std::cout << result << '\n';
    }
    return 0;
}