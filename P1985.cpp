#if 0
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#pragma GCC optimize(2)
#pragma G++ optimize(2)
using namespace std;
int n,m,u,v,s,t;
vector<int> vis;
vector<vector<int> >adj;
stack<int> path;
stack<int> tmp;
inline int read()
{
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}//是符号
    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}//是数字
    return x*s;
}
inline void find_path(int s,int t)
{
	int q,next;
	tmp.push(s);
	while(!tmp.empty())
	{
		bool flag=false;
		q=tmp.top();
		vis[q]=1;
		if(q==t)
			break;
		for(int i=0;i<adj[q].size();i++)
		{
			next=adj[q][i];
			if(vis[next]==0)
			{
				vis[next]=1;
				tmp.push(next);
				flag=true;
				break;
			}
			else if(adj[next].size()!=0)
			{
				adj[q].erase(adj[q].begin()+i);
				i--;
			}
		}
		if(flag==false)
		{
			tmp.pop();
		}
	}
}
inline void print_path()
{
	if(tmp.empty())
	{
		cout << "-1\n";
		return;
	}
	int count=tmp.size();
	cout << count << '\n';
	while(!tmp.empty())
	{
		path.push(tmp.top());
		tmp.pop();
	}
	while(!path.empty())
	{
		cout << path.top() << ' ';
		path.pop();
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cin >> n >> m >> s >> t;
	n=read();m=read();s=read();t=read();
	vis.resize(n+1,0);
	adj.resize(m+1);
	for(int i=1;i<=m;i++)
	{
		u=read();v=read();
		adj[u].push_back(v);
	}
	find_path(s,t);
	print_path();
}
#endif