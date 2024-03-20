#if 0
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

const int N = 100005, M = N * 2;
int h[N], ne[M], e[M], w[M], idx;
int n, m;
int st[N], p[N], dist[N], res[M];
vector<PII> query[N];
inline int read()
{
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}//是符号
    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}//是数字
    return x*s;
}
inline void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

inline int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void dfs(int u, int fa) //算距离的技巧
{
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j == fa)
            continue;
        dist[j] = dist[u] + w[i];
        dfs(j, u);
    }
}

void tarjan(int u)
{
    st[u] = 1;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            tarjan(j);
            p[j] = u;
        }
    }

    for (auto it : query[u]) // 处理已经访问过的点和当前点的最长距离
    {
        int y = it.first, id = it.second;
        if (st[y] == 2)
        {
            int ans = find(y);
            res[id] = dist[y] + dist[u] - 2 * dist[ans];
        }
    }

    st[u] = 2;
}

int main()
{
    n=read();
    memset(h, -1, sizeof(h));
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        a=read();
        b=read();
        c=read();
        add(a, b, c), add(b, a, c);
    }

    for (int i = 1; i <= n; i++)
        p[i] = i;

    m=read();
    for (int i = 0; i < m; i++)
    {
        int a, b;
        a=read();b=read();
        if (a != b)
        {
            query[a].push_back({b, i});
            query[b].push_back({a, i});
        }
    }

    dfs(1, -1);

    tarjan(1);

    for (int i = 0; i < m; i++)
        printf("%d\n", res[i]);

    return 0;
}
#endif 