#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, x[10005], y[10005], iMem[10005][10005];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    
    for (int i = 1; i <= m; ++i)
        cin >> y[i];
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (x[i] != y[j])
                iMem[i][j] = max(iMem[i - 1][j], iMem[i][j - 1]);
            else
                iMem[i][j] = iMem[i - 1][j - 1] + 1;
        }
    
    cout << iMem[n][m];
    return 0;
}