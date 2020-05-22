#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n,0);
    long long sum = 0;
    for(int i=0;i<n-1;i++){
        cin>>v[i];
        sum += (long long)v[i];
    }
    long long intendedSum = (long long)n*(n+1)/2;
    cout<<intendedSum-sum;
    return 0;
}