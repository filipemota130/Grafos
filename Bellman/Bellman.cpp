#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

int main()
{
    int n, m, src; 
    cin >> n >> m >> src;
    src--;

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) //Recebe 
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }

    //int src;
    //cin >> src;
    vector<int> dist(n, INT_MAX);
    dist.at(src) = 0;

    for (int i = 0; i < n-1; i++)
    {
        for (auto e: edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            dist[v] = min(dist[v], w + dist[u]);
        }
    }

    for (auto i: dist)
    {
        cout << i << endl;
    }
}