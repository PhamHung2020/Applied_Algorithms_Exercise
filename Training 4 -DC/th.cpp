#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    vector<int> arr{0, 1, 1, 5, 7, 8};
    int stt = 1;
    map<vector<int>, int> m;
    do
    {
        if (arr[0] != 0 && !m[arr])
        {
            cout << stt << ". ";
            for (int i = 0; i < 6; ++i)
                cout << arr[i];
            cout << '\n';
            ++stt;
            m[arr] = 1;
        }
    } while (next_permutation(arr.begin(), arr.end()));
    return 0;
}