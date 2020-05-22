#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> ar(n,0);
    vector<int> dep(n,0);
    for(int i=0;i<n;i++){
        cin>>ar[i]>>dep[i];
    }

    // Sweep Line Algorithm
    vector<pair<int,int> > day;
    for(int i=0;i<n;i++){
        day.push_back({ar[i],1}); 
        // 1 -> arrival, kept smaller so that if both (arr, dep) are on same day, arrival should come first in sorted order
        day.push_back({dep[i],2});
    }

    sort(day.begin(),day.end());
    int roomsNeeded = 0, curCheckedIn = 0;
    
    for(int i=0;i<2*n;i++){
        if(day[i].second == 1) curCheckedIn += 1; // new arrival
        else curCheckedIn -=1;  // a departure
        roomsNeeded = max(roomsNeeded, curCheckedIn);
    }

    // vector<int> cust;
    // int avRoom = 1;
    // for(int i=0;i<2*n;i++){
    //     if(day[i].second == 2){
    //         cust.push_back(avRoom);
    //         avRoom = (avRoom + 1)%roomsNeeded
    //     }

    // }

    cout<<roomsNeeded<<"\n";

    return 0;
}