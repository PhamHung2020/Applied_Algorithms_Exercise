#include <iostream>
#define MAX 10000010

using namespace std;

int n, k;
long long mPositive[MAX + 1];
long long mNegative[MAX + 1];

long long min(long long m[])
{
    long long min = 0;
    long long carry = 0;
    long long soLan = 0;
    long long i = MAX;
    while (i > 0)
    {
        while (i > 0 && m[i] == 0)
            --i;
        if (i == 0)
            break;

        if (m[i] > carry)
        {
            m[i] -= carry;
            if (m[i] <= k)
            {
                soLan = 1;
                carry = k - m[i];
            }
            else
            {
                soLan = m[i] / k;
                carry = k - m[i] % k;
                if (carry == k)
                    carry = 0;
                else
                    soLan++;
            }

            min += 2 * soLan * i;
        }
        else
        {
            carry -= m[i];
        }
        m[i] = 0;
    }
    return min;
}

int main()
{
    long long x, m;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        if (x >= 0)
            cin >> mPositive[x];
        else
            cin >> mNegative[-x];
    }

    cout << min(mPositive) + min(mNegative);
    return 0;
}