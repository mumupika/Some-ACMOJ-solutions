#if 0
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<memory.h>
#define LL long long
using namespace std;
#define fstqwq (int)(1e5+10)
vector<LL>g1[fstqwq],g2[fstqwq];
vector<LL>col[fstqwq];
LL color[fstqwq],n,m,k=0;
stack<LL>s;
bool vis[fstqwq];
inline void dfs1(LL u) 
{
	vis[u]=false;
	for(LL i=0;i<g1[u].size();i++) 
    {
		LL v=g1[u][i];
		if (vis[v]) 
            dfs1(v);
	}
	s.push(u);
}
inline void dfs2(int u) 
{
	col[k].push_back(u); 
    color[u]=k; 
    vis[u]=false;
	for(LL i=0;i<g2[u].size();i++) 
    {
		LL v=g2[u][i];
		if (vis[v]) 
        dfs2(v);
	}
}
int main() 
{
	ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
	cin>>n>>m;
	for(LL i=1;i<=m;i++) {
		LL x,y; cin>>x>>y;
		g1[x].push_back(y);
		g2[y].push_back(x);
	}
	memset(vis,true,sizeof(vis));
	for(LL i=1;i<=n;i++) 
        if (vis[i]) 
            dfs1(i);
	memset(vis,true,sizeof(vis));
	while (!s.empty()) 
    {
		LL t=s.top(); 
        s.pop();
		if (vis[t]) 
        {
			++k; 
            dfs2(t);
		}
	}
	for(LL i=1;i<=k;i++) 
        sort(col[i].begin(),col[i].end());
    memset(vis,true,sizeof(vis));
    LL cnt,count=0;
	for(LL i=1;i<=n;i++)
		if (vis[color[i]]) 
        {
            cnt=0;
			for(LL j=0;j<col[color[i]].size();j++) 
            {
                //out<<col[color[i]][j]<<" ";
                cnt++;
            }
			vis[color[i]]=false;
            count+=cnt*(cnt-1)/2;
		}
    cout << count << '\n';
	return 0;
}
#endif
#if 0
#include<bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;

struct edge{
	int to,nxt;
}e[maxn];

int head[maxn],dfn[maxn],low[maxn],n,m,tim;
bool vis[maxn];
long long ans,cnt;

stack<int>st;

void tarjan(int u){
	dfn[u]=low[u]=++tim;
	st.push(u);
	vis[u]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(vis[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		cnt=0;
		int pos;
		do{
			pos=st.top();
			st.pop();
			cnt++;
			vis[pos]=0;
		}while(pos!=u);
		ans+=cnt*(cnt-1)/2;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		e[++cnt]=(edge){v,head[u]};
		head[u]=cnt;
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	printf("%lld",ans);
}
#endif