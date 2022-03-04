// TTUD_Graph_S.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int numOfBug, numOfInterac;
vector<vector<int>> adjList;
vector<int> dis;
bool isOk = true;
void Dfs(int v)
{
    for (int i = 0; i < adjList[v].size(); ++i)
    {
        int next = adjList[v][i];
        if (dis[next] == -1)
        {
            dis[next] = 1 - dis[v];
            Dfs(next);
            if (!isOk)
                return;
        }
        else if (dis[v] == dis[next])
        {
            isOk = false;
            return;
        }
    }
}

void StartDfs()
{
    isOk = true;
    for (int i = 1; i <= numOfBug; ++i)
    {
        if (!isOk)
            return;
        if (dis[i] == -1)
        {
            dis[i] = 0;
            Dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numOfTest;
    cin >> numOfTest;
    for (int test = 1; test <= numOfTest; ++test)
    {
        cin >> numOfBug >> numOfInterac;
        adjList.resize(numOfBug + 2, vector<int>());
        int a, b;
        for (int i = 1; i <= numOfInterac; ++i)
        {
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        dis.resize(numOfBug + 2, -1);
        StartDfs();
        cout << "Scenario #" << test << ":\n";
        if (isOk)
            cout << "No suspicious bugs found!\n";
        else
            cout << "Suspicious bugs found!\n";
        
        adjList.clear();
        dis.clear();
    }
}
