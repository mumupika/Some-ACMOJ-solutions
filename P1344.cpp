#if 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 10;
int in[maxn],tnt,fst[maxn],nxt[maxn << 1],n,m,u,v,w;
ll dis[maxn];
struct edge{
    int u,v,w;
}side[maxn << 1];
void add(int u,int v,int w) {
    side[++tnt] = {u,v,w};
    nxt[tnt] = fst[u];
    fst[u] = tnt;
}
int q[maxn << 8],head = 0,tail = -1,cnt[maxn],pre[maxn],vis[maxn];
int SPFA(int s) {
    head = 0,tail = -1;
    for(int i = 0; i <= n; ++i)
        dis[i] = 1ll + 1e15,cnt[i] = 0,in[i] = 0,pre[i] = 0;
    //cout << dis[s] << endl;
    dis[s] = 0;in[s] = 1;q[++tail] = s;
    while(head <= tail) {
        int u = q[head++]; vis[u] = 1; in[u] = 0;
        for(int i = fst[u]; i; i = nxt[i]) {
            int v = side[i].v,w = side[i].w;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pre[v] = u;
                if(!in[v])
                    cnt[v] += 1,q[++tail] = v,in[v] = 1;
                if(cnt[v] >= n) return v;
            }
        }
    }
    return -1;
}
vector<int> ans;
int main() {
    //freopen("in","r",stdin);
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    int ret = -1;
    for(int i = 1; i <= n; ++i)
        if(!vis[i]) {
            ret = SPFA(i);
            if(ret != -1) break;
        }
    if(ret == -1) cout << "0";//spa fa fa
    else {
        //cout << "-1";return 0;
        for(int i = 1; i <= n; ++i)
            in[i] = 0,ret = pre[ret];
        in[0] = 1;
        while(in[ret] == 0) {
            in[ret] = 1;
            ans.push_back(ret);
            ret = pre[ret];
        }
        cout << ans.size() << "\n";
        for(int i = ans.size() - 1; i >= 0; --i)
            printf("%d ",ans[i]);
    }
    return 0;
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
const int MAXM = 6205;
typedef long long LL;
int n, m, fir[MAXN], nxt[MAXM], to[MAXM], w[MAXM], cnt;
//链式前向星：
void link(int u, int v, int wt) {
    to[++cnt] = v; nxt[cnt] = fir[u]; fir[u] = cnt; w[cnt] = wt;
}

LL dis[MAXN];
int tim[MAXN], pre[MAXN];
queue<int>q;
bool inq[MAXN], vis[MAXN];
int ans[MAXN];

bool spfa(int S) {
    //q是队列，dis是距离（最短距离）
    dis[S] = 0; q.push(S); inq[S] = 1;
    //inq是这里的“是否已访问过该节点”
    int flg = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = 0;
        if(++tim[u] > n) {
            flg = u;
            break;
        }
        //这一步是遍历该点所邻接的所有点，我这里是链式前向星，根据采用的数据结构自己改
        for(int i = fir[u], v; i; i = nxt[i])
            if(dis[v=to[i]] > dis[u] + w[i]) {
                dis[v] = dis[u] + w[i];
                pre[v] = u;
                if(!inq[v]) inq[v] = 1, q.push(v);
            }
    }
    //后面是输出一个负环（如果有）
    if(!flg) return 0;
    puts("Yes");
    vis[flg] = 1; int k;
    for(int i = pre[flg]; ; i = pre[i]) {
        if(vis[i]) { k = i; break; }
        vis[i] = 1;
    }
    int tot = 1; ans[1] = k;
    for(int i = pre[k]; i != k; i = pre[i]) ans[++tot] = i;
    printf("%d\n", tot);
    for(int i = tot; i; --i) printf("%d ", ans[i]);
    return 1;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1, u, v, wt; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &wt);
        link(u, v, wt);
    }
    memset(dis, 0x3f, sizeof dis);
    for(int i = 1; i <= n; ++i)
        if(dis[i] == dis[0]) {
            if(spfa(i)) return 0;
        }
    puts("No");
}
#endif