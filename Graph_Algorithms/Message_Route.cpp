#include<bits/stdc++.h>
using namespace std;

#define MAX ((int)1e5 + 5)

vector<vector<int> > adj(MAX,vector<int>());
vector<int> vis(MAX,0);
int n,m;
vector<int> prevOnPath(MAX,-1);

bool bfs(int st){
    queue<int> q;
    q.push(st);
    vis[st] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v == n) return true;
        for(auto nbr: adj[v]){
            if(vis[nbr] == 0){
                vis[nbr] = 1;
                q.push(nbr);
                prevOnPath[nbr] = v;
            }
        }
    }
    return false;
}

int main(){
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bool found = bfs(1);
    if(found){
        int cur = n;
        vector<int> path;
        while(cur != -1){
            path.push_back(cur);
            cur = prevOnPath[cur];
        }
        reverse(path.begin(),path.end());
        cout<<path.size()<<"\n";
        for(int i=0;i<path.size();i++){
            cout<<path[i]<<" ";
        }
    }
    else cout<<"IMPOSSIBLE";
    return 0;
}