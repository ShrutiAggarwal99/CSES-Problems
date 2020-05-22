#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> desired(n,0);
    set<int> av;
    int x;
    for(int i=0;i<n;i++) cin>>desired[i];
    for(int i=0;i<m;i++){
        cin>>x;
        av.insert(x);
    }

    int cnt = 0;
    for(int i=0;i<n;i++){
        int lb = desired[i]-k;
        int ub = desired[i]+k;
        auto it = lower_bound(av.begin(),av.end(),lb);
        if(it == av.end()) continue;
        if((*it) <= ub){
            cnt++;
            // cout<<i<<" "<<(*it)<<"\n";
            av.erase(*it);
        }
    }
    
    cout<<cnt;

    return 0;
}