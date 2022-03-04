#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    bool isDecreasing = true;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] != n - i)
        {
            isDecreasing = false;
        }
    }

    if (isDecreasing)
    {
        cout << -1;
        return 0;
    }

    next_permutation(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}