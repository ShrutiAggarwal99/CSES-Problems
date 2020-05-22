#include<bits/stdc++.h>
using namespace std;

#define MAX (int)1e3

vector<vector<char> > g(MAX,vector<char>(MAX,'\0'));
int n,m;

vector<vector<char> > path(MAX,vector<char>(MAX,'\0'));
string ans = "";
int ei = -1, ej = -1;

bool bfs(int si, int sj){
    int n = g.size(), m = g[0].size();
    queue<pair<int,int> > q;
    q.push({si,sj});
    int i,j;
    while(!q.empty()){
        auto fp = q.front();
        q.pop();
        i = fp.first;
        j = fp.second;
        
        if(i+1<n && g[i+1][j] == '.'){
            g[i+1][j] = '#';
            path[i+1][j] = 'D';
            q.push({i+1,j});
        }
        else if(i+1<n && g[i+1][j] == 'B'){
            path[i+1][j] = 'D';
            ei = i+1, ej=j;
            return true;
        }
        if(i-1>=0 && g[i-1][j] == '.'){ 
            g[i-1][j] = '#';
            path[i-1][j] = 'U';
            q.push({i-1,j});
        }
        else if(i-1>=0 && g[i-1][j] == 'B'){
            path[i-1][j] = 'U';
            ei = i-1, ej=j;
            return true;
        }
        if(j+1<m && g[i][j+1] == '.'){
            g[i][j+1] = '#';
            path[i][j+1] = 'R';
            q.push({i,j+1});
        }
        else if(j+1<m && g[i][j+1] == 'B'){
            path[i][j+1] = 'R';
            ei = i, ej=j+1;
            return true;
        }
        if(j-1>=0 && g[i][j-1] == '.'){
            g[i][j-1] = '#';
            path[i][j-1] = 'L';
            q.push({i,j-1});
        }
        else if(j-1>=0 && g[i][j-1] == 'B'){
            path[i][j-1] = 'L';
            ei = i, ej=j-1;
            return true;
        }
    }
    return false;
}

int main(){
    cin>>n>>m;
    int si,sj;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j] == 'A') si=i, sj=j;
        }
    }

    bool found = bfs(si,sj);
    if(!found) cout<<"NO";
    else{
        cout<<"YES\n";
        // cout<<ei<<" "<<ej<<"\n";
        while(g[ei][ej] != 'A'){
            ans += path[ei][ej];
            if(path[ei][ej] == 'L') ej++;
            else if(path[ei][ej] == 'R') ej--;
            else if(path[ei][ej] == 'D') ei--;
            else if(path[ei][ej] == 'U') ei++;
        }
        reverse(ans.begin(),ans.end());
        cout<<ans.length()<<"\n"<<ans;
    }
    return 0;
}