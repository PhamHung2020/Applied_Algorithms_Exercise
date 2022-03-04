#include <iostream>
#define OFF 14

using namespace std;

int c[13], c1[40], c2[40], dd[13][13], n, m;
int res;

void Try(int x)
{
    for(int i = 1; i <= n; ++i)
    {
        if(!c[i])
            if(!dd[x][i])
                if(!c1[x + i])
                    if(!c2[OFF + x - i])
                    {
                        c[i] = 1;
                        c1[x + i] = 1;
                        c2[OFF + x - i] = 1;
                        if(x == n) 
                            res++; 
                        else 
                            Try(x + 1);
                        c2[OFF + x - i] = 0;
                        c1[x + i] = 0;
                        c[i] = 0;
                    }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1)
    {
        cin >> n >> m;
        if(!n)
            break;

        for(int i = 1; i <= m; ++i)
        {
            int x,y;
            cin >> x >> y;
            dd[x][y] = 1;
        }

        Try(1);

        cout << res << '\n';
        for (int i = 0; i < 13; ++i)
            for (int j = 0; j < 13; ++j)
                dd[i][j] = 0;

        res = 0;
    }
    return 0;
}