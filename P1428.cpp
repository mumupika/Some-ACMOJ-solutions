#if 0
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long LL;

struct edge {
    int node;
    int w;
    edge(int n, int ww): node(n), w(ww) {}
};
struct dist {
    LL w;
    int u;
    dist(LL _w, int _u): w(_w), u(_u) {}
};
struct dist_cmp {
    bool operator() (dist& d1, dist& d2) {
        return d1.w > d2.w;
    }
};

int got_edge(int u, int v, vector<edge>* neighbors) {
    vector<edge>& u_edge = neighbors[u];
    for (int i = 0; i < u_edge.size(); ++i) {
        if (u_edge[i].node == v) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, m;
    scanf("%d%d%", &n, &m);
    int s = 1; int t = n;

    vector<edge> neighbors[n+1];
    while (m--) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if (u==v) continue;
        
        int index = got_edge(u,v,neighbors);
        if (index >= 0) {
            if (neighbors[u][index].w > w) {
                neighbors[u][index].w = w;
                neighbors[v][got_edge(v, u, neighbors)].w = w;
            }
        }
        else {
            neighbors[u].push_back(edge(v,w));
            neighbors[v].push_back(edge(u,w));
        }
    }

    bool mark[n+1]; 
    for(int i=0;i<n+1;i++)
        mark[i]=0;
    mark[s] = 1;
    priority_queue<dist, vector<dist>, dist_cmp> dist_heap;
    vector<edge>& s_edge = neighbors[s];
    for (edge& i : s_edge) {
        dist_heap.push(dist(i.w, i.node));
    }

    int ans = 0;
    for (int i=1; i<n; ++i) {
        dist tmp_dist = dist_heap.top(); dist_heap.pop();
        while (mark[tmp_dist.u]) {
            tmp_dist = dist_heap.top(); dist_heap.pop();
        }

        int node = tmp_dist.u;
        mark[node] = 1;
        ans += tmp_dist.w;

        vector<edge>& tmp_edge = neighbors[node];
        for (edge& i : tmp_edge) {
            dist_heap.push( dist(i.w, i.node) );
        }
    }

    printf("%lld", ans);

    return 0;
}
#endif
#if 0
//借助并查集定位节点记录路线
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 1e5 + 5;
int n, m, total, l;
int f[MAXN]{};

struct edge
{
	int u;
	int v;
	int w;
};
edge graph[MAXN << 1];

bool comparew(edge e1, edge e2)
{
	return e1.w < e2.w;
}

int fastfind(int u)
{
	f[u] = f[u] != u ? fastfind(f[u]) : f[u];
	return  f[u];
}

void init()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> graph[i].u >> graph[i].v >> graph[i].w;
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
}

int main()
{
	init();
	l = 1;
	sort(graph + 1, graph + 1 + m, comparew);
	for (int i = 1; i <= m; i++)
	{
		if (fastfind(graph[i].u) != fastfind(graph[i].v))
		{
			graph[i].u = fastfind(graph[i].u);
			graph[i].v = fastfind(graph[i].v);
			f[graph[i].v] = graph[i].u;
			l++;
			total += graph[i].w;
		}
		if (l == n)
		{
			cout << total << endl;
			return 0;
		}
	}
	return 0;
}
#endif
#if 0
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define LL long long
const LL maxn=1000005;
struct Edge
{
    LL to,nxt,val;
}edge[maxn];

LL cnt,head[maxn],vis[maxn],pre[maxn],key[maxn];
LL n,m,s,t,u,v,w;
struct node
{
    LL pos,key;
};

priority_queue<node> Q;
void add_edge(LL u,LL v,LL w)
{
    edge[++cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
bool operator<(const node &x, const node &y) { return x.key > y.key; }
void MST_PRIM()
{
    int count=0,res=0;
    for(int i=0;i<=n;i++)
        key[i]=__LONG_LONG_MAX__;
    key[1]=0;
    pre[1]=0;
    Q.push(node{1,0});
    while(!Q.empty())
    {
        if(count>=n) break;
        int u=Q.top().pos;
        int u_key=Q.top().key;
        Q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        ++count;
        res+=u_key;
        for(int i=head[u];i;i=edge[i].nxt)
        {
            int v=edge[i].to;
            int w=edge[i].val;
            if(w<key[v])
            {
                key[v]=w;
                pre[v]=w;
                Q.push(node{v,w});
            }
        }
    }
    cout << res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    //memset(head,-1,sizeof(LL)*n);
    for(int i=1;i<=m;i++)
    {
        cin >> u >> v >> w;
        add_edge(u,v,w);
        add_edge(v,u,w);//undirected;
    }
    MST_PRIM();
}
#endif
#if 0
#include <iostream>
#include<algorithm>
using namespace std;

const int N = 1e5+5;
int n, m, ans, cnt, fa[N];

struct Edge{
    int u, v, w;
} a[N*4];
bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}
int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    for(int i = 1; i <= n; i++)
        fa[i] = i;
    sort(a+1, a+m+1, cmp);
    for(int i = 1; i <= m; i++) {
        int u = find(a[i].u), v = find(a[i].v);
        if(u == v) continue;
        fa[u] = v;
        cnt++;
        ans += a[i].w;
        if(cnt == n-1) {
            break;
        }
    }
    if(cnt == n-1) cout << ans;
    else cout << "impossible";
    return 0;
}
#endif