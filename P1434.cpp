#if 0
#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;

priority_queue<ll, vector<ll>, greater<ll>> biheap;


ll alloc(int n)
{
    ll u = 0, v = 0;
    ll answer = 0;
    for (int i = 1; i < n; i++)
    {
        u = biheap.top();
        biheap.pop();
        answer += u;
        v = biheap.top();
        biheap.pop();
        answer += v;
        biheap.push(u + v);
    }
    return answer;
}

void init(int n)
{
    ll a;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        biheap.push(a);
    }
}

int main()
{
    int n, w, p;
    cin >> n >> w >> p;
    init(n);
    cout << int(ceil(alloc(n) * p / 100.0)) << endl;
    return 0;
}
#endif
#if 0
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main(){
    int n,w,p;
    int tmp;
    double s = 0;
    long long ans = 0;
    cin>>n>>w>>p;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i = 0;i < n;++i){
        cin>>tmp;
        q.push(tmp);
    }
    int a,b,c;
    while(q.size() > 1){
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        c = a + b;
        s += c;
        q.push(c);
    }
    s = ceil(s * p / 100);
    ans = int(s);
    cout<<ans;
    return 0;
}
#endif