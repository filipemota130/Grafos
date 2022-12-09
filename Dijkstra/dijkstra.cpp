#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

int main(){
    int n,m,v,u,w;

    cin >> n >> m;

    vector<vector<pair<int,int>>> Grafo(n);

    for(int i=0; i<m; i++){
        w=1;
        cin >> v >> u >> w;
        v--; u--;
        Grafo[v].push_back({u,w});
        Grafo[u].push_back({v,w});
    }

    priority_queue<pair<int,int>> dj;//vertice,distancia
    vector<int> dist(n, INT_MAX);

    dist[0] = 0;
    dj.push({0,0});
    while (dj.size() > 0) {
        int v = dj.top().second;
        int w = -dj.top().first;
        dj.pop();
        if(w != dist[v]) continue;

        for(auto edge:Grafo[v]){
            int u = edge.first;
            int w = edge.second;
            if (dist[u] > dist[v]+w){
                dist[u] = dist[v]+w; 
                dj.push({-dist[u], u});
            }
        }
    }
    int i = 0;
    for(int d: dist){
        i++;
        if (d == INT_MAX){
            d = -1;
        }
        cout << i << ":" << d <<" ";
    }
    cout << endl;
}