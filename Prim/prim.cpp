#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;

int main(){
    cin >> n >> m and n;
    vector< vector<pair<int,int> > > Grafo(n); //lista de adjacencia
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> v >> u >> w;
        v; u;
        Grafo[v].push_back({u,w});
        Grafo[u].push_back({v,w});
    }
    priority_queue< pair<int,int> > prim;
    vector<bool> mark(n, false);
    vector<pair<int,int> > lista;
    mark[0] =true;
    for(pair<int,int> edge:Grafo[0]){
        prim.push({-edge.second, edge.first});
    }
    int sum=0;
    while(prim.size()){
        pair<int,int> menor = prim.top();
        lista.push_back(menor);
        prim.pop();

        if(mark[menor.second]== true) continue;
        sum += -menor.first;
        mark[menor.second] = true;
        for(pair<int,int> ed: Grafo[menor.second]){
            if (mark[ed.first] == true) continue;
            prim.push({-ed.second, ed.first});
        }
    }
    for (int i=0; i<lista.size(); i++){
        cout << lista[i].first << ":" << lista[i].second << endl;
    }
    cout << sum << endl; 
}