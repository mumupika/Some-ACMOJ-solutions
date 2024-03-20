#if 0
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct Point
{
    double x,y;
};
inline bool cmp_x(const Point &a,const Point &b)
{
    return a.x<b.x;
}
inline bool cmp_y(const Point &a,const Point &b)
{
    return a.y<b.y;
}
inline double distance(const Point &a,const Point &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double solve(int l,int r,Point *a,Point *b)
{
    if(r-l<=1) return INFINITY;
    if(l+2==r) return distance(a[l],a[l+1])+distance(a[l],a[r])+distance(a[r],a[l+1]);

    int mid=(l+r)>>1,cnt=0;
    double dist=min(solve(l,mid,a,b),solve(mid+1,r,a,b));
    for(int i=l;i<=r;i++)
        if(fabs(a[i].x-a[mid].x)<dist*0.5)
            b[++cnt]=a[i];
    sort(b+1,b+1+cnt,cmp_y);
    for(int i=1;i<=cnt;i++)
        for(int j=i+1;j<=cnt;j++)
        {
            if((b[j].y-b[i].y)>dist*0.5) break;
            for(int k=j+1;k<=cnt;k++)
                if(b[k].y-b[i].y>dist*0.5) break;
                else dist=min(dist,distance(b[i],b[j])+distance(b[j],b[k])+distance(b[i],b[k]));
        }
    return dist;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    Point a[n+1],b[n+1];
    for(int i=1;i<=n;i++)
        cin >> a[i].x >> a[i].y;
    sort(a+1,a+n+1,cmp_x);
    printf("%.9f",solve(1,n,a,b));
}
#endif