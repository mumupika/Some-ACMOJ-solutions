#if 0
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
#define mst(s, t) memset(s, t, sizeof(s))
const int INF = 0x3f3f3f3f;
const int maxn = 10010;
vector<int> G[maxn];
int ans[maxn], num, n;
int dfs(int node, int father)
{
    int sum = 1, childmax = 0;   //若是叶子结点则return sum=1，否则求其子树(包括自己)的总结点数
    for(int i=0; i<G[node].size(); i++)
    {
        if(G[node][i] == father)continue; //因为是树结构，这里可以在无向时避免遍历成环
        int sum_son = dfs(G[node][i], node);
        childmax = max(sum_son, childmax);//所有子树的结点数的最大值
        sum += sum_son;//sum:node的子树的结点数和
    }
    childmax = max(childmax, n-sum);
    if(childmax <= n/2)
    {
        /*
         * 当node结点的孩子结点的结点数最大为Sum,若Sum<=n/2,则该点符合条件
         * 因为去掉node后，任意子树结点数<=n/2, max()保证其非子树结点和仍<=n/2
         * 故该点满足条件
        */
        ans[num++] = node;
    }
    return sum;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for(int i=0; i<n-1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    num = 0;
    int tmp = dfs(1, 0);
    //cout << n << "==" << tmp << endl; //验证
    sort(ans, ans+num);
    if(num){
        for(int i=0; i<num; i++){
            printf("%d\n", ans[i]);
        }
    }else{
        printf("NONE\n");
    }
    return 0;
}
#endif