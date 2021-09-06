#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 5;
bool visited[MAX];
vector<pair<long long, int>> graph[MAX];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> colaPrioridad;

long long primMST(int x) {

    int vecinos; 
    long long pesoTotal = 0;

    pair<long long, int> nodoActual;

    colaPrioridad.push(make_pair(0, x));
    while(!colaPrioridad.empty()) { 

        nodoActual = colaPrioridad.top(); 
        colaPrioridad.pop(); 
        x = nodoActual.second; 
        if(visited[x]) { 
            continue;
        }
        pesoTotal+= nodoActual.first; 
        visited[x] = true;
        for(int i = 0; i<graph[x].size(); i++) { 
            vecinos = graph[x][i].second;
            if(!visited[vecinos]) { 
                colaPrioridad.push(graph[x][i]);
            }
        }
    }
    return pesoTotal;
}

int main() {
    int n, m;
    cin>>n>>m;
    int x, y, peso;
    for(int i = 0; i<m; i++) {
        cin>>x>>y>>peso;
        graph[x].push_back(make_pair(peso,y));
        graph[y].push_back(make_pair(peso,x));
    }
    long long minCost = primMST(0);
    cout<<minCost<<endl;
    return 0;
}
