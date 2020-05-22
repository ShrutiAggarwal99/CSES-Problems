#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n,0);
    long long cnt = 0;
    long long cumSum = 0;
    set<long long> prefixSums;
    prefixSums.insert(0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        cumSum += a[i];
        if(prefixSums.find(cumSum-x) != prefixSums.end()) cnt++;
        prefixSums.insert(cumSum);
    }
    cout<<cnt<<"\n";

    return 0;
}

// T.C = O(nlogn)
