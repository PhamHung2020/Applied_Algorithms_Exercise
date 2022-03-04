#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

struct edge
{
    int u;
    int v;
    int weight;
};

int n, numTree;
pair<int, int> xy[550];
vector<edge> edges;
vector<edge> tree;
bool visited[550];
bool isOk = false;
int parents[100100];

int findRoot(int x)
{
    if (parents[x] == 0)
        return x;
    parents[x] = findRoot(parents[x]);
    return parents[x];
    //return findRoot(parents[x]);
}


int dist(int i, int j)
{
    int x1 = xy[i].first;
    int x2 = xy[j].first;
    int y1 = xy[i].second;
    int y2 = xy[j].second;
    return (int)sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}


bool edge_cmp(const edge& a, const edge& b)
{
    return a.weight < b.weight;
}

void mst()
{
    sort(edges.begin(), edges.end(), edge_cmp);
    int size = edges.size();
    for (int i = 0; i < size; ++i)
    {
        int rootU = findRoot(edges[i].u);
        int rootV = findRoot(edges[i].v);
        if (rootU != rootV)
        {
            parents[rootU] = rootV;
            tree.push_back(edges[i]);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> xy[i].first >> xy[i].second;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            edge e;
            e.u = i;
            e.v = j;
            e.weight = dist(i, j);
            edges.push_back(e);
        }
    }

    mst();
    cout << tree[tree.size() - 1].weight;
    return 0;

}