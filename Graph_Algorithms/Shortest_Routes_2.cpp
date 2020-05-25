// FLOYD WARSHALL (ALL PAIR SHORTEST PATHS) - negative edge wts allowed though this ques won't have them

#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 501;

const ll INF = (ll)1e12+5;

// take distance matrix of long long type, coz the max distance between any 2 pairs can be 5e2*1e9 (~5e11) for given constraints
vector<vector<ll> > dist(MAX,vector<ll>(MAX,INF)); // take input of graph's adjacency matrix in this (since initially it is equal to the adjacency matrix of graph)
int n,m,q;

int main(){
    cin>>n>>m>>q;
    int a,b,c;
    for(int i=1;i<=m;i++){
        // undirected graph, but there might be more than 2 undirected weighted edges between 2 vertices, so always keep the smaller one
        cin>>a>>b>>c;
        ll curWt = dist[a][b];
        if(c < curWt) dist[a][b] = c, dist[b][a] = c;
        dist[a][a] = dist[b][b] = 0; //just setting up initial adjacency matrix, since all values are set INF by default
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k] < INF && dist[k][j] < INF) // to prevent distances from becoming INF-2 or INF-5 kind of in case of negative wt. edges present
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=1;i<=q;i++){
        cin>>a>>b;
        if(dist[a][b] < INF) cout<<dist[a][b]<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}
