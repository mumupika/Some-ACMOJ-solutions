#if 0
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
#define LL long long
struct Pair
{
    LL x,y,dis;
    LL distance_2(const Pair& other) const
    {
        return (x-other.x)*(x-other.x)+(y-other.y)*(y-other.y);
    }
};
bool cmp(Pair &a,Pair &b)
{
    return a.x<b.x;
}
bool cmp_y(Pair &a,Pair &b)
{
    return a.y<b.y;
}
LL solve(Pair *a,int l,int r)
{
    if(l+1>=r)
        return __LONG_LONG_MAX__;
    
    int m=(l+r)/2;
    LL ret=min(solve(a,l,m),solve(a,m,r));
    vector <Pair> temp;
    for(LL i=l;i<r;i++)
    {
        if((a[i].x-a[m].x)*(a[i].x-a[m].x)<ret)
        {
            temp.push_back(a[i]);
        }
    }
    sort(temp.begin(),temp.end(),cmp_y);
    for(LL i=0;i<temp.size();i++)
    {
        for(LL j=i+1;j<temp.size();j++)
        {
            if((temp[i].y-temp[j].y)*(temp[i].y-temp[j].y)>=ret)
                break;
            ret=min(ret,temp[i].distance_2(temp[j]));
        }
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    LL n;
    cin >> n;
    LL max=__LONG_LONG_MAX__;
    Pair a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(a,a+n,cmp);

    cout << solve(a,0,n) << '\n';
}
#endif