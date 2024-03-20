#if 0
#include<iostream>
using namespace std;
#define ll long long
const ll maxn=10005;
ll tree[maxn][2];
void dfs(ll root)
{
    if(root<=0) return;
    dfs(tree[root][1]);//后序遍历：先访问右节点再访问左节点；
    dfs(tree[root][0]);
    printf("%lld ",root);
    return;
}
int main()
{
    ll n,root=-999;
    scanf("%lld",&n);
    while(n--)
    {
        ll a;
        scanf("%lld",&a);
        if(root==-999) root=a;
        scanf("%lld",&tree[a][0]);//储存左节点之值。
        scanf("%lld",&tree[a][1]);//储存右节点之值。
    }
    dfs(root);
    printf("\n");
    return 0;
}
#endif