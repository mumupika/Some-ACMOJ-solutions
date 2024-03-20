#if 0
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 2505;
const int MAXM = 6205*2;
typedef long long LL;
int n, m, fir[MAXN], nxt[MAXM], to[MAXM], w[MAXM], cnt;

void link(int u, int v, int wt) {
    to[++cnt] = v; nxt[cnt] = fir[u]; fir[u] = cnt; w[cnt] = wt;
}

LL dis[MAXN];
queue<int>q;
bool inq[MAXN];
LL spfa(int S, int T) {
    memset(dis, 0x3f, sizeof dis);
    dis[S] = 0; q.push(S); inq[S] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = 0;
        for(int i = fir[u], v; i; i = nxt[i])
        if(dis[v=to[i]] > dis[u] + w[i]) {
            dis[v] = dis[u] + w[i];
            if(!inq[v]) inq[v] = 1, q.push(v);
        }
    }
    return dis[T];
}

int main() {
    int s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i = 1, u, v, wt; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &wt);
        link(u, v, wt), link(v, u, wt);
    }
    printf("%lld\n", spfa(s, t));
}
#endif
#if 0
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 2505;
const int MAXM = 6205*2;
typedef long long LL;
int n, m, fir[MAXN], nxt[MAXM], to[MAXM], w[MAXM], cnt;

void link(int u, int v, int wt) {
    to[++cnt] = v; nxt[cnt] = fir[u]; fir[u] = cnt; w[cnt] = wt;
}

LL dis[MAXN];
queue<int>q;
bool inq[MAXN];
LL spfa(int S, int T) {
    memset(dis, 0x3f, sizeof dis);
    dis[S] = 0; q.push(S); inq[S] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = 0;
        for(int i = fir[u], v; i; i = nxt[i])
        if(dis[v=to[i]] > dis[u] + w[i]) {
            dis[v] = dis[u] + w[i];
            if(!inq[v]) inq[v] = 1, q.push(v);
        }
    }
    return dis[T];
}

int main() {
    int s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i = 1, u, v, wt; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &wt);
        link(u, v, wt), link(v, u, wt);
    }
    printf("%lld\n", spfa(s, t));
}
#endif
#if 0
#include<bits/stdc++.h>
#define LL long long
const LL MaxN = 100010, MaxM = 500010;

struct edge
{
    LL to, dis, next;
};

edge e[MaxM];
LL head[MaxN], dis[MaxN], cnt;
bool vis[MaxN];
LL n, m, s, t;

inline void add_edge(LL u,LL v,LL d )
{
    cnt++;
    e[cnt].dis = d;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;

    cnt++;
    e[cnt].dis=d;
    e[cnt].to=u;
    e[cnt].next=head[v];
    head[v]=cnt;
}

struct node
{
    LL dis;
    LL pos;
    bool operator <( const node &x )const
    {
        return x.dis < dis;
    }
};

std::priority_queue<node> q;


inline void dijkstra()
{
    dis[s] = 0;
    q.push( ( node ){0, s} );
    while( !q.empty() )
    {
        node tmp = q.top();
        q.pop();
        int x = tmp.pos, d = tmp.dis;
        if( vis[x] )
            continue;
        vis[x] = 1;
        for( int i = head[x]; i; i = e[i].next )
        {
            int y = e[i].to;
            if( dis[y] > dis[x] + e[i].dis )
            {
                dis[y] = dis[x] + e[i].dis;
                if( !vis[y] )
                {
                    q.push( ( node ){dis[y], y} );
                }
            }
        }
    }
}


int main()
{
    scanf( "%lld%lld%lld%lld", &n, &m, &s, &t);
    for(int i = 1; i <= n; ++i)
        dis[i] = __LONG_LONG_MAX__;
    for(int i = 0; i < m; ++i )
    {
        LL u, v, d;
        scanf( "%lld%lld%lld", &u, &v, &d );
        add_edge( u, v, d );
    }
    dijkstra();
    printf("%lld",dis[t]);
    return 0;
}
#endif