#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, k;
vector<int> p;
vector<int> pos;
long long sum = 0;

bool check(long long mid)
{
    int index = k - 2;
    int sumSinglePart = 0;
    long long totalSum = sum;
    for (int i = m - 1; i >= 0; --i)
    {
        if (index < 0)
            break;
        if (sumSinglePart + p[i] <= mid && i > index)
        {
            sumSinglePart += p[i];
        }
        else
        {
            pos[index] = i;
            --index;
            totalSum -= sumSinglePart;
            sumSinglePart = p[i];
        }
    }
    return totalSum <= mid;
}

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        sum = 0;
        cin >> m >> k;
        p.clear();
        p.resize(m);
        pos.clear();
        pos.resize(k - 1);
        for (int i = 0; i < m; ++i)
        {
            cin >> p[i];
            sum += p[i];
        }
        sort(p.begin(), p.end());

        if (k == 1)
        {
            cout << sum << '\n';
            --t;
            continue;
        }

        long long bot = p[m - 1];
        long long top = sum;
        long long mid, ans = p[m - 1];
        while (bot <= top)
        {
            mid = (top + bot) / 2;
            if (check(mid))
            {
                ans = mid;
                top = mid - 1;
            }
            else
                bot = mid + 1;
        }
        check(ans);
        int index = 0;
        for (int i = 0; i < m; ++i)
        {
            if (i < m - 1)
                cout << p[i] << ' ';
            else
                cout << p[i];
            if (index < k - 1 && i == pos[index])
            {
                cout << "/ ";
                ++index;
            }
        }
        cout << '\n';
        --t;
    }

    return 0;
}