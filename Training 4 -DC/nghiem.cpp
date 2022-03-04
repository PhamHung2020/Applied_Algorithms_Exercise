#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const double PI = atan(1) * 4;

int N, F;
double radius[10005];
double S[10005];
double maxS, bot, top, ans, mid;

bool check(double x)
{
    if (pow(x, 19) - x * x - x + 1 > 1e-6)
        return true;
    return false;
}

int main()
{
    
        bot = 0;
        top = 1;
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
        
    

    return 0;
}