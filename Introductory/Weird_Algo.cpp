#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n; 
    // imp to use long long, otherwise in some cases like larger n, the simulation might cross upper limit of int and either never stops or gives wrong result
    cin>>n;
    cout<<n<<" ";
    while(n>1){
        if(n&1) n = 3*n + 1;
        else n = n/2;
        cout<<n<<" ";
    }
    return 0;
}