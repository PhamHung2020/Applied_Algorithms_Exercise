#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

struct jug
{
    int a;
    int b;
    int n;

    jug(int A, int B, int N)
    {
        a = A;
        b = B;
        n = N;
    }
};

queue<jug> q;
bool isVisited[1000][1000];

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    if (c == a || c == b)
    {
        cout << 0;
        return 0;
    }

    jug first(a, 0, 1);
    isVisited[a][0] = true;
    jug second(0, b, 1);
    isVisited[0][b] = true;

    isVisited[0][0] = true;
    isVisited[a][b] = true;

    q.push(first);
    q.push(second);
    while (!q.empty())
    {
        jug top = q.front();

        if (top.a == c || top.b == c)
        {
            cout << top.n;
            break;
        }

        int n = top.n + 1;

        if (!isVisited[a][top.b])
        {
            q.push(jug(a, top.b, n));
            isVisited[a][top.b] = true;
        }

        if (!isVisited[top.a][b])
        {
            q.push(jug(top.a, b, n));
            isVisited[top.a][b] = true;
        }

        if (!isVisited[top.a][0])
        {
            q.push(jug(top.a, 0, n));
            isVisited[top.a][0] = true;
        }

        if (!isVisited[0][top.b])
        {
            q.push(jug(0, top.b, n));
            isVisited[0][top.b] = true;
        }

        if (top.a > 0 && top.b < b)
        {
            int sum = top.a + top.b;
            if (sum < b && !isVisited[0][sum])
            {
                q.push(jug(0, sum, n));
                isVisited[0][sum] = true;
            }
            else if (sum > b && !isVisited[sum - b][b])
            {
                q.push(jug(sum - b, b, n));
                isVisited[sum - b][b] = true;
            }
        }

        if (top.b > 0 && top.a < a)
        {
            int sum = top.a + top.b;
            if (sum < a && !isVisited[sum][0])
            {
                q.push(jug(sum, 0, n));
                isVisited[sum][0] = true;
            }
            else if (sum > a && !isVisited[a][sum - a])
            {
                q.push(jug(a, sum - a, n));
                isVisited[a][sum - a] = true;
            }
        }

        q.pop();
    }

    if (q.empty())
        cout << -1;

    return 0;
}