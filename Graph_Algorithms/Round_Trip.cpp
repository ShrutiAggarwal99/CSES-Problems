#include<bits/stdc++.h>
using namespace std;

#define MAX ((int)1e5 + 5)

vector<vector<int> > adj(MAX,vector<int>());
vector<int> par(MAX,0); // also does the work of marking visited nodes(when par = 0, the node is unvisited, is visited in all other cases)
int n,m;
bool cycleFound = false;

void printCycle(int st){
    cycleFound = true;
    vector<int> cycle;
    cycle.push_back(st);
    int v = par[st];
    while(v != st){
        cycle.push_back(v);
        v = par[v];
    }
    cycle.push_back(st);
    cout<<cycle.size()<<"\n";
    for(int i=0;i<cycle.size();i++) cout<<cycle[i]<<" ";
}

void dfs(int v){
    for(auto nbr: adj[v]){
        if(par[nbr] == 0) par[nbr] = v, dfs(nbr); // unvisited neighbor
        else if(nbr != par[v]) par[nbr] = v, printCycle(v); // visited non-parent neighbor (means cycle is there)
        if(cycleFound) return;
    }
}

int main(){
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(par[i] == 0){ // means i is unvisited node
            par[i] = -1;  // dummy value of parent for root of all connected components
            dfs(i);
            if(cycleFound) break;
        }
    }

    if(!cycleFound) cout<<"IMPOSSIBLE";

    return 0;
}