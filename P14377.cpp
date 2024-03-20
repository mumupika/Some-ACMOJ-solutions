#if 0
#include<iostream>
#define maxn 10005
#define mod 1000000007
int main()
{
    long long n,f[maxn];
    scanf("%lld",&n);
    f[0]=1,f[1]=1;f[2]=2;
    for(int i=3;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            (f[i]+=f[j]*f[i-j-1]%mod)%=mod;
        }
    }
    printf("%lld\n",f[n]);
    return 0;
}
#endif
//左子树个数✖️右子树个数=总二叉搜索树的个数。
//例：f(5)=42;
//f(5)=f(4)*f(0)+f(3)*f(1)+f(2)^2+f(1)*f(3)+f(0)*f(4)=14+5+4+5+14=42;