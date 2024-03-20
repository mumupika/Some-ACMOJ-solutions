#if 0
//vector algorithm
#include <iostream>
#include <vector>
using namespace std;
int n, m, u, v;
const int N = 100010;
int a[N];
vector<int> edge[N];
void dfs(int q, int d)
{
    if(a[q]) 
        return;
    a[q] = d;
    for (int i = 0; i < edge[q].size(); i++)
        dfs(edge[q][i], d);
    return;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        edge[v].push_back(u);
    }
    for (int i = n; i >= 1; i--) 
        dfs(i, i);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}
#endif