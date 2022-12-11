#include<bits/stdc++.h>
#include <limits.h>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> iPair;

void primMST(vector<vector<pair<int,int>>> Grafo, int V)
{
    priority_queue <iPair, vector <iPair>, greater<iPair>> pq;
 
    int src = 0;

    vector<int> key(V, INT_MAX);

    vector<int> parent(V, -1);

    vector<bool> inMST(V, false);
 
    pq.push(make_pair(0, src));
    key[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(inMST[u] == true)
        {
            continue;
        }
       
        inMST[u] = true;
        vector< pair<int, int> >::iterator i;
        for (i = Grafo[u].begin(); i != Grafo[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (inMST[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i < V; ++i)
    {
        cout << "(" << parent[i] + 1 << "," << i+1 << ")" << " ";
        sum += key[i];
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
    primMST(Grafo, n);
    return 0;
}