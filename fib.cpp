#include <iostream>

using namespace std;

long long fib[10010];

long long calFib(int n)
{
    if (fib[n] != -1)
        return fib[n];
    fib[n] = calFib(n - 1) + calFib(n - 2);
    return fib[n];
}

int mthFib(int n, int m)
{
    //cout << n << ' '  << m << '\n';
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    int lengthFirstFib = calFib(n - 1);
    if (lengthFirstFib >= m)
        return mthFib(n - 1, m);
    return mthFib(n - 2, m - lengthFirstFib);
}

int main()
{
    for (int i = 0; i <= 10000; ++i)
        fib[i] = -1;
    fib[0] = 1;
    fib[1] = 1;
    fib[2] = 1;
    int n, m;
    cin >> n >> m;
    cout << mthFib(n, m);
    return 0;
}