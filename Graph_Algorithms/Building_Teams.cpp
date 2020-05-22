#include<bits/stdc++.h>
using namespace std;

#define MAX ((int)1e5 + 5)

vector<vector<int> > adj(MAX,vector<int>());
vector<int> col(MAX,-1);  // will act as visited array also
int n,m;

bool dfs(int v, int c){
    col[v] = c;
    for(auto nbr: adj[v]){
        if(col[nbr] == -1){
            if(dfs(nbr, (c^1)) == false) return false;
        }
        else if(col[nbr] == c) return false;
    }
    return true;
}

int main(){
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isBipartite = true;
    for(int i=1;i<=n;i++){
        if(col[i] == -1){
            isBipartite = dfs(i,0);
            if(isBipartite == false){
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<col[i]+1<<" ";
    }

    return 0;
}