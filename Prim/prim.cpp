#include<bits/stdc++.h>
#include <limits.h>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> dupla;

void prim(vector<vector<pair<int,int>>> Grafo, int V)
{
    priority_queue <dupla, vector <dupla>, greater<dupla>> pq; //alternativa para inverter a ordem da queue
 
    int src = 0;

    vector<int> dist(V, INT_MAX);

    vector<int> parent(V, -1);

    vector<bool> check(V, false);
 
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(check[u] == true)
        {
            continue;
        }
       
        check[u] = true;
        for (auto edge:Grafo[u])
        {
            int v = edge.first;
            int weight = edge.second;
            if (check[v] == false && dist[v] > weight)
            {
                dist[v] = weight;
                pq.push(make_pair(dist[v], v));
                parent[v] = u;
            }
        }
    }
    int sum = 0;
    //mostrar resultado
    for (int i = 1; i < V; ++i)
    {
        cout << "(" << parent[i] + 1 << "," << i+1 << ")" << " ";
        sum += dist[i];
    }
    cout << endl << "Peso total da árvore geradora: " << sum << endl;
}

int main()
{
    int n, m, v, u, w;
    cin >> n >> m;
    vector <vector<pair<int,int>>> Grafo(n);
    //Aceita Apenas Vértices possitivos >0
    for(int i = 0; i < m; i++)
    {
        cin >> v >> u >> w;
        v--, u--;
        Grafo[v].push_back({u, w});
        Grafo[u].push_back({v, w});
    }
    prim(Grafo, n);
    return 0;
}