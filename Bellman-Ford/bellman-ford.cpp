#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

void Bellman(vector<vector<int>> Grafo, int n){
    vector<int> dist(n, INT_MAX);
    int src;
    cin >> src;
    dist[src - 1] = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto e: Grafo)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if (dist[u] != INT_MAX && ((dist[u] + w) < dist[v]))
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    int counter = 1;
    for (auto i: dist){
        cout << counter << ":" << i << " ";
        counter++;
    }
    cout << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> Grafo;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        Grafo.push_back({u, v, w});
        Grafo.push_back({v, u, w});
    }
    Bellman(Grafo, n);
    
}