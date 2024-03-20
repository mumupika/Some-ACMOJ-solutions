#if 0
#include<iostream>
#define ll long long
using namespace std;
#define maxn 1000005
const ll INF=10000005;
int a[maxn],low[maxn];
int n,ans;
int binary_search(int R,int x)
{
    int L=1,mid;
    while(L <= R)
    {
        mid=(L+R)>>1;
        if(low[mid]<=x)
            L=mid+1;
        else
            R=mid-1;
    }
    return L;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        low[i]=INF;//minimum value of low;
    }
    low[1]=a[1];
    ans=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>low[ans])
        {
            ans++;
            low[ans]=a[i];
        }
        else
        {
            int temp=binary_search(ans,a[i]);
            low[temp]=a[i];
        }
    }
    cout << ans << '\n';
    return 0;
}
#endif