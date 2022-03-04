#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const double PI = atan(1) * 4;

int N, F;
double radius[10005];
double S[10005];
double maxS, bot, top, ans, mid;

bool check(double mid)
{
    int sum = 0;
    for (int i = 0; i < N; ++i)
    {
        sum += S[i] / mid;
    }
    return sum > F;
}

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        cin >> N >> F;
        maxS = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> radius[i];
            S[i] = radius[i] * radius[i] * PI;
            maxS = max(maxS, S[i]);
        }

        bot = 0;
        top = maxS;
        while (top - bot >= 1e-6)
        {
            mid = (top + bot) / 2;
            if (check(mid))
            {
                ans = mid;
                bot = mid;
            }
            else
            {
                top = mid;
            }
        }
        printf("%.6f\n", ans);
        --t;
    }

    return 0;
}