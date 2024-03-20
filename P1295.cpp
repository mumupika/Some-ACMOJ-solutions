#if 0
#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,left[500005],right[500005],count=0;
    left[1]=1;
    cin >> n;
    if(n>=500000)
    {
        printf("0\n");
        return 0;
    }

    //质数筛：
    for(int i=2;i<=n;i++)
    {
        if(left[i]==0)
            right[++count]=i;//2是质数，不筛除。
        for(int j=1;(j<=count && right[j]*i<=n);j++)//找出范围内的质数个数
        {
            left[i*right[j]]=1;//标记出接下来也要筛除的；
            if(i%right[j]==0) break;
        }
    }
    printf("%lf\n",double(2*count)/double(n*n));
    return 0;
}
#endif