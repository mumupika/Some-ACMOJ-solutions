#if 0
#include<iostream>
#include<queue>
using namespace std;

const int NMAX = 205;
int r[NMAX][NMAX]{};
bool visit[NMAX]{};
int pre[NMAX]{};
int m, n;

bool BFS(int s, int t)  
{
    int p;
    queue<int> q;
    for (int i = 0; i < NMAX; i++)
    {
        pre[i] = 1;
        visit[i] = false;
    }
    pre[s] = s;
    visit[s] = true;
    q.push(s);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (r[p][i] > 0 && !visit[i])
            {
                pre[i] = p;
                visit[i] = true;
                if (i == t) 
                    return true;
                q.push(i);
            }
        }
    }
    return false;
}

int FordFulkerson(int s, int t)
{
    int flow = 0;
    while (BFS(s, t))
    {
        int d = 0x7fffffff;
        for (int i = t; i != s; i = pre[i])
        {
            d = d < r[pre[i]][i] ? d : r[pre[i]][i];
        }
        for (int i = t; i != s; i = pre[i])
        {
            r[pre[i]][i] -= d;
            r[i][pre[i]] += d;
        }
        flow += d;
    }
    return flow;
}

int main()
{
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        r[u][v] += w;
    }
    cout << FordFulkerson(1, n) << endl;
    return 0;
}
#endif
#if 0
#include<bits/stdc++.h>
#define N 10005
#define M 1000005
#define INF 100000005
using namespace std;
// Codes provided by TA. fstqwq. url: https://acm.sjtu.edu.cn/OnlineJudge/problem?problem_id=1449 
struct edge {
    int next, to, flow;
};
edge e[M * 2]; // back edges
int edge_cnt = 2; // to make reverse(e[x]) = e[x ^ 1], and avoid use number 0
int list_head[N]; // init as 0
int source, sink;	// Save the S and T vertex 
void add_edge (int u, int v, int flow);
int cur[N];   // 
int level[N]; // level graph
int n, m;
int dfs(int x, int flow);
int dinic();
bool make_level();	// return the level graph if have.
int main(){
	scanf("%d%d",&n,&m);
	int u,v,c;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&c);
		add_edge(u,v,c);
	}
	source = 1; sink = n;
    printf("%d\n",dinic());
    return 0;
}

void add_edge (int u, int v, int flow) {
    e[edge_cnt] = {list_head[u], v, flow};
    list_head[u] = edge_cnt++;
    e[edge_cnt] = {list_head[v], u, 0};
    list_head[v] = edge_cnt++;
}

bool make_level(){
	for(int i=1;i<=n;i++)
		level[i] = INF;
	queue<int>q; q.push(source); level[source] = 0; cur[source] = list_head[source];
    while(!q.empty()){
        int x = q.front();q.pop();
//        printf("Start at %d\n",x);
        for(int i = list_head[x];i;i = e[i].next){
//        	printf("Make level at %d\n", i);
            int y = e[i].to;
            if(e[i].flow > 0 && level[y] == INF){
                q.push(y);
//                printf("Output %d\n",y);
                cur[y] = list_head[y];
                level[y] = level[x] + 1;
                if(y == sink) return true;
            }
        }
    }
//    printf("False\n");
	return false;
}

int dfs(int x, int flow) {
    if (x == sink) return flow;
    int used = 0;
    for (int &i = cur[x]; i != 0; i = e[i].next) // i : reference to cur[x]
        if (e[i].flow > 0 && level[x] + 1 == level[e[i].to]) {
            int ret = dfs(e[i].to, min(e[i].flow, flow - used));
            used += ret;
            e[i].flow -= ret;
            e[i ^ 1].flow += ret;
            if (used == flow) break;
        }
    return used;
}
int dinic() {
    int ans = 0;
    while (make_level()) {
        for (int i = 1; i <= n; i++) // initialize cur[]
            cur[i] = list_head[i];
        ans += dfs(source, INF);
    }
    return ans;
}
// Dinic's Algorithm
/* Refferrence: https://blog.csdn.net/weixin_30729609/article/details/99581407
初始化，计算剩余图;
while （BFS()）{　　　　 // BFS过程的作用：1，计算层次图；2，当汇点不再层次图内时返回0
	path.clear();
	源点入栈path;　　　 // 栈path保存层次图内从原点到终点的可行路径
	while (源点的出度不为0){
		u <- path.top;
		if  (u != 汇点){　　　　　　　 // 在层次图内寻找一条从起点到终点的路径
			if  (u出度大于0)
				将层次图内与u相连的点v入栈；
			else{
				u出栈；　　　　　　 // 从path中删除
				u的level = 正无穷；    // 从层次图中删除
			}
		}
		else{　　　　　　　　　 // 对路径增广
			在剩余图中沿P增广；
			令path.top为从起点可到达的最后一个顶点；
		}
	}
}
*/
#endif
#if 0
/**
 * Reference: https://oi-wiki.org/graph/flow/max-flow/
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
#define maxn 250
#define INF 0x3f3f3f3f

struct Edge {
	int from, to, cap, flow;

	Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

struct EK {
	int n, m;             // n：点数，m：边数
	vector<Edge> edges;   // edges：所有边的集合
	vector<int> G[maxn];  // G：点 x -> x 的所有边在 edges 中的下标
	int a[maxn], p[maxn];  // a：点 x -> BFS 过程中最近接近点 x 的边给它的最大流
                         // p：点 x -> BFS 过程中最近接近点 x 的边

	void init(int n) 
	{
		for (int i = 0; i < n; i++) 
			G[i].clear();
			edges.clear();
	}

	void AddEdge(int from, int to, int cap) 
	{
		edges.push_back(Edge(from, to, cap, 0));
		edges.push_back(Edge(to, from, 0, 0));
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	int Maxflow(int s, int t) 
	{
		int flow = 0;
		for (;;) 
		{
			memset(a, 0, sizeof(a));
			queue<int> Q;
			Q.push(s);
			a[s] = INF;
			while (!Q.empty()) 
			{
				int x = Q.front();
				Q.pop();
				for (int i = 0; i < G[x].size(); i++) 
				{  // 遍历以 x 作为起点的边
					Edge& e = edges[G[x][i]];
					if (!a[e.to] && e.cap > e.flow) 
					{
	    	    	    p[e.to] = G[x][i];  // G[x][i] 是最近接近点 e.to 的边
	    	    	    a[e.to] = min(a[x], e.cap - e.flow);  // 最近接近点 e.to 的边赋给它的流
						Q.push(e.to);
					}
				}
	    		if (a[t]) break;  // 如果汇点接受到了流，就退出 BFS
			}
			if (!a[t])
	    	    break;  // 如果汇点没有接受到流，说明源点和汇点不在同一个连通分量上
			for (int u = t; u != s; u = edges[p[u]].from) 
			{  // 通过 u 追寻 BFS 过程中 s -> t 的路径
	    	    edges[p[u]].flow += a[t];      // 增加路径上边的 flow 值
	    	    edges[p[u] ^ 1].flow -= a[t];  // 减小反向路径的 flow 值
			}
			flow += a[t];
		}
		return flow;
	}
};
int main()
{
	EK G;
	int V,E;
	cin >> V >> E;
	G.init(V);
	int s,t;
	for(int i=1,u,v,c;i<=E;i++)
	{
		cin >> u >> v >> c;
		G.AddEdge(u,v,c);
	}
	int res=G.Maxflow(1,V);
	cout << res;
}
#endif