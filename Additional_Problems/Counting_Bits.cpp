#include<bits/stdc++.h>
using namespace std;

#define ll long long int

// GETTING RUNTIME ERROR RIGHT NOW

int main(){
    ll n;
    cin>>n;
    int grpSize = 2;
    ll perGrp = 1; 
    ll ans = 0;
    n += 1;
    while(n > grpSize){
        ll fullGrps = n/grpSize;
        ans += fullGrps*perGrp;
        ans += (n%grpSize > grpSize/2) ? n%grpSize - grpSize/2 : 0;
        perGrp *= 2;
        grpSize *= 2;
    }
    if(n == grpSize) ans += perGrp;
    else ans += (n - (grpSize/2)) > 0 ? n - (grpSize/2) : 0;
    cout<<ans;
    return 0;
}