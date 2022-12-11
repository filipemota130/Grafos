#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

int main(){
    int n,m;cin >> n >> m;
    vector<vector<int>> edges;

    for (int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        edges.push_back({u,v,w});
        edges.push_back({v,u,w});
    }
    vector<int> dist(n,INT_MAX);
    int src;
    cin >> src;
    dist[src-1] = 0;
    for (int i=0;i<n;i++){
        for (auto e: edges){
            int u= e[0];
            int v= e[1];
            int w= e[2];
            if (dist[u] !=INT_MAX && ((dist[u]+w) < dist[v])){
                dist[v]= dist[u]+w;
            }
        }
    }
    int count = 1;
    for (auto i:dist){
        cout << count << ":"<< i << " ";
        count++;
    }
    cout<<'\n';
}