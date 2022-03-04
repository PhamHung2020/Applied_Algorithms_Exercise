// TTUD_Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int f, s, g, u, d;
vector<vector<int>> adjList;
vector<int> dis;

void Bfs()
{
    vector<bool> isVisited(f + 5, false);
    isVisited[s] = true;
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    while (!q.empty())
    {
        int currentFloor = q.front();
        for (int i = 0; i < adjList[currentFloor].size(); ++i)
        {
            int adjFloor = adjList[currentFloor][i];
            if (!isVisited[adjFloor])
            {
                isVisited[adjFloor] = true;
                q.push(adjFloor);
                dis[adjFloor] = dis[currentFloor] + 1;
                if (adjFloor == g)
                    return;
            }
        }
        q.pop();
    }
}

int main()
{
    cin >> f >> s >> g >> u >> d;
    adjList.resize(f + 5, vector<int>());

    for (int i = 1; i <= f; ++i)
    {
        if (i + u <= f)
            adjList[i].push_back(i + u);
        if (i - d > 0)
            adjList[i].push_back(i - d);
    }
    dis.resize(f + 5, -1);
    Bfs();
    if (dis[g] != -1)
        cout << dis[g];
    else
        cout << "use the stairs";
    return 0;

}