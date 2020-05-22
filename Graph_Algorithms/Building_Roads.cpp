#include<bits/stdc++.h>
using namespace std;

#define MAX ((int)1e5 + 5)

vector<vector<int> > adj(MAX,vector<int>());
vector<int> vis(MAX,0);
int n,m;

void dfs(int v){
    vis[v] = 1;
    for(auto nbr: adj[v]){
        if(vis[nbr] == 0) dfs(nbr);
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
    int nc = 0;
    vector<int> heads;

    for(int i=1;i<=n;i++){
        if(vis[i] == 0) heads.push_back(i), dfs(i), nc++;
    }

    cout<<nc-1<<"\n";
    for(int i=0;i<nc-1;i++){
        cout<<heads[i]<<" "<<heads[i+1]<<"\n";
    }

    return 0;
}