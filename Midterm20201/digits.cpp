#include <iostream>

using namespace std;
int n, cnt = 0;
int digits[10];
bool isVisited[10];

// v = 0, a = 1, c = 2, i = 3, n = 4, e = 5, o = 6, d = 7

void solve(int k)
{
    if (k == 8)
    {
        int vaccine = digits[0] * 1000000 + digits[1] * 100000 + digits[2] * 11000 + digits[3] * 100 + digits[4] * 10 + digits[5];
        int covid19 = digits[2] * 1000000 + digits[6] * 100000 + digits[0] * 10000 + digits[3] * 1000 + digits[7] * 100 + 19;
        if (vaccine - covid19 == n)
            ++cnt;
        return;
    }

    int startPoint = (k != 0 && k != 2) ? 0 : 1;
    for (int i = startPoint; i < 10; ++i)
    {
        if (!isVisited[i])
        {
            isVisited[i] = true;
            digits[k] = i;
            solve(k + 1);
            isVisited[i] = false;
        }
    }
}

int main()
{
    // freopen("./test-DIGITS/Test-offline/DIGITS.IN11", "r", stdin);
    int t;
    cin >> t;
    while (t > 0)
    {
        cin >> n;
        cnt = 0;
        for (int i = 0; i < 10; ++i)
            isVisited[i] = false;
        solve(0);
        cout << cnt << '\n';
        --t;
    }
    return 0;
}