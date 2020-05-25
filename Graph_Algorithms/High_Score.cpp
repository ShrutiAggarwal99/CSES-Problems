#include<bits/stdc++.h>
using namespace std;

// The problem is longest path (with both +ve and -ve edge weights possible)
// It is also said - for arbitrarily large values, return -1 (basically case of positive cycles - in which case meaning of longest path is lost)
// We change the signs of edge weights when taking input, and hence change the problem to shortest path
// But in case of negative cycle - return -1 (since no meaning of shortest path left then) 
// -> this negative cycle is originally positive cycle which wouldn't make sense for original problem  - hence transformation of problem stand right.
// Classic Bellmann Ford for SSSP Problem (since -ve weights are also there)

#define ll long long int
const ll INF = (ll)1e12 + 5;

// for Bellman ford, represent graph as an edge list
vector<vector<ll> > edgeList; // a,b,w : a->b with weight w
vector<ll> d(2501,INF); // to store distance of every node from source node
int n,m;

vector<vector<pair<int,int> > > adjList(2501,vector<pair<int,int> >()); // only to store if there is an edge between 2 vertices and hence run dfs later
vector<vector<int> > valid(2501,vector<int>(2501,0));
vector<int> vis(2501,0);

void dfs(int src, int v){
    vis[v] = 1;
    valid[src][v] = 1;
    for(auto e: adjList[v]){
        int u = e.first, w = e.second;
        if(vis[u] == 0) dfs(src,u);
    }
}

int main(){
    cin>>n>>m;
    int a,b,w;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>w;
        edgeList.push_back({a,b,-w});
        adjList[a].push_back({b,-w});
    }

    // O(n^2) - dfs on every node 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) vis[j] = 0;
        dfs(i,i);
    }

    int src = 1;
    d[src] = 0; // 1 is the start node
    
    for(int it=1;it<=n;it++){
        for(auto e: edgeList){
            a = e[0], b = e[1], w = e[2];
            if(d[a] < INF && d[b] > w + d[a]){ // update only when there is a path from source to node a, imp to use this INF condition since there are -ve wts. also
                d[b] = w + d[a];
                if(it == n && valid[1][b] == 1 && valid[b][n] == 1){ // if weight updates in nth iteration
                    cout<<"-1\n"; 
                    return 0;
                }
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++) cout<<valid[i][j]<<" ";
    //     cout<<"\n";
    // }
    
    if(d[n] == INF) cout<<"-1\n"; // no path from 1 (source) to n
    else cout<<(-d[n])<<"\n";  // negative coz we had inverted the signs of the weights to transform problem to shortest path
    return 0;
}