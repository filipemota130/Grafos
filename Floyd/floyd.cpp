#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX =1e9;

void floyd(vector<vector<int>> Grafo,int n){
    vector<vector<int>> dist = Grafo;
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (dist[i][k] + dist[j][k] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[j][k];    
                }
            }
        }   
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (dist[i][j] == MAX){
                cout<<"INF ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int n, w;
    cin >> n;
    vector<vector<int>> Grafo(n);
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            cin >> w;
            if (w == -1){
                w=MAX;
            }
            Grafo[i].push_back(w);
        }
    }
    floyd(Grafo, n);
}