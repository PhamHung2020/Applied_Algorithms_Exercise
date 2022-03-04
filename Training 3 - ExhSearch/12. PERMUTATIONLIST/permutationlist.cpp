#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> arr;

void print(const vector<int> &arr)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << ' ';
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        arr.push_back(i);

    if (k == 1)
    {
        print(arr);
        return 0;
    }

    int m = 1;
    while (m < k && next_permutation(arr.begin(), arr.end()))
        m++;
    if (m != k)
        cout << -1;
    else
        print(arr);
    return 0;
}