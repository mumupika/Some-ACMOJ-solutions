#if 0
#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin >> N;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq1;
    priority_queue<int> pq2;
    map<int,int> mp;
    int ans=N;
    for(int i=0;i<N;i++){
        int A,B; cin >> A >> B;
        if(A<B){
            mp[A]--; mp[B]++;
            ans--;
        }
        else pq1.emplace(B,A);
    }
    int cnt=0;
    for(auto x:mp){
        while(!pq1.empty()&&pq1.top().first<=x.first){
            pq2.push(pq1.top().second); pq1.pop();
        }
        cnt+=x.second;
        while(cnt<0){
            if(pq2.empty()||pq2.top()<=x.first){
                cout << -1 << endl; return 0;
            }
            cnt++; ans--;
            mp[pq2.top()]--; pq2.pop();
        }
    }
    cout << ans << endl;
}
#endif