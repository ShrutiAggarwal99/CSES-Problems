#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n;
    set<int> s; // not using unordered_set because that is giving TLE (maybe worst case scenario of O(n) reaching for some large input)
    for(int i=0;i<n;i++){
        cin>>x;
        s.insert(x);
    }
    cout<<s.size();
    return 0;
}