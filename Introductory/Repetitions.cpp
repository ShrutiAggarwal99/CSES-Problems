#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin>>s;
    n = s.length();
    int i=0;
    int maxCnt = 0;
    while(i<n){
        char c = s[i];
        int cnt = 0;
        while(i<n && s[i] == c){
            i++;
            cnt++;
        }
        maxCnt = max(maxCnt,cnt);
    }
    cout<<maxCnt;
    return 0;
}