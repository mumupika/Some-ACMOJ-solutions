#if 0
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    ll n,m;
    scanf("%lld%lld",&m,&n);
    ll *a;
    a=new ll [m*n];
    for(ll i=0;i<m*n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+(m*n));//STL排序；
    ll Volume;
    scanf("%lld",&Volume);
    if(Volume==0)
    {
        printf("%lld.00\n0.00",a[0]);
        return 0;
    }
    ll id;
    double res1,res2;
    ll height = 0;
    for (id = 1;id<m*n; id++) 
    {
        height+=(a[id]-a[id - 1]) * (id);
        if (height>=Volume)
            break;
    }
    if(id < m*n)
        height -= (a[id] - a[id - 1]) * (id);
    //假定水平面高度为x。这样我们在求取的时候会出现未知量。这时，采用的是将我们数组中的一个高度设置为水平高。
    //然后一次推进计算，直到逼近水的体积。逼近的计算方法请参考horner法则。
    //例如：1 2 3 4 5 6
    //设3为水平高度时，有：3-1+3-2=2-1+3-2+3-2=2-1+（3-2）*2.
    //设4为水平高度时，有4-1+4-2+4-3=2-1+（3-2）*2+（4-3）*3.
    res1 = a[id - 1] + 1.0 * (Volume - height) / (id);
    res2 = 1.0 * id / (m * n) * 100;
    printf("%.2lf\n%.2lf", res1, res2);
    return 0;
}
#endif