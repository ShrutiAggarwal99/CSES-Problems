#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char> > &g, int i, int j){
    int n = g.size(), m = g[0].size();
    if(i<0 || i>=n || j<0 || j>=m || g[i][j] == '#') return;
    g[i][j] = '#';
    dfs(g,i+1,j);
    dfs(g,i-1,j);
    dfs(g,i,j-1);
    dfs(g,i,j+1);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char> > g(n,vector<char>(m,'0'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>g[i][j];
    }

    int nc = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j] == '.') dfs(g,i,j), nc++;
        }
    }

    cout<<nc;

    return 0;
}