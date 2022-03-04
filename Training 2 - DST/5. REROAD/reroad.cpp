#include <iostream>
#include <vector>

using namespace std;

vector<int> t;

int main()
{
    t.push_back(-1000000005);

    int N;
    cin >> N;

    int numOfRoad = 0;
    int temp;
    for (int i = 1; i <= N; ++i)
    {
        cin >> temp;
        t.push_back(temp);
        if (t[i] != t[i - 1])
            ++numOfRoad;
    }

    int Q;
    cin >> Q;

    int p, c, left, right;
    for (int i = 0; i < Q; ++i)
    {
        cin >> p >> c;
        if (c == t[p])
        {
            cout << numOfRoad << '\n';
            continue;
        }

        if (p != 1)
        {
            left = t[p - 1];
            if (t[p] != left && c == left)
                --numOfRoad;
            else if (t[p] == left && c != left)
                ++numOfRoad;
        }

        if (p != N)
        {
            right = t[p + 1];
            if (t[p] != right && c == right)
                --numOfRoad;
            else if (t[p] == right && c != right)
                ++numOfRoad;
        }

        t[p] = c;
        cout << numOfRoad << '\n';
    }
    return 0;
}