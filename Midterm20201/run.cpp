#include <iostream>

using namespace std;
int n;
int a[100100];

int main()
{
    freopen("./test-RUN/Test1/RUN.inp", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int cnt = 1;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] <= a[i - 1])
            ++cnt;
    }
    freopen("./test-RUN/Test1/RUN.out", "r", stdin);
    int result;
    cin >> result;
    if (result == cnt)
        cout << "PASSED";
    else
        cout << "FAILED";
    return 0;
}