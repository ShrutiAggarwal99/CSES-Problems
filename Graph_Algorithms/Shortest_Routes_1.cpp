#include<bits/stdc++.h>
using namespace std;

#define MAX ((int)1e5+5)
#define INF ((long long)1e15+5)

vector<vector<pair<int,int> > > adj(MAX,vector<pair<int,int> >());
int n,m;
vector<long long> dist(MAX,INF);
// vector<int> processed(MAX,0);

void dijkstra(int src){
    // priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq; // min priority queue
    set<pair<long long, int> > ds;
    dist[src] = 0;
    ds.insert({dist[src],src});
    while(!ds.empty()){
        pair<long long,int> p = *(ds.begin()); // pair of {dist,vertex} - minimum distance unprocessed vertex
        ds.erase(p); // O(logn)
        int v  = p.second;
        for(auto edge: adj[v]){ //relaxing every edge from vertex v 
            if(dist[edge.first] > dist[v] + edge.second){
                ds.erase({dist[edge.first],edge.first});  // O(logn)
                dist[edge.first] = dist[v] + edge.second;
                ds.insert({dist[edge.first],edge.first}); // O(logn)
            }
        }
    }
    // T.C = O(nlogn + mlogn)
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;  // a->b with edge weight = c
        adj[a].push_back({b,c});
    }

    dijkstra(1);

    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}