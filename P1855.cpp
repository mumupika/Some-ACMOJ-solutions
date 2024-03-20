#if 0
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<cctype>
#include<cassert>
#include<climits>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define RepD(i,n) for(int i=n;i>=0;i--)
#define MEM(a) memset(a,0,sizeof(a))
#define MEMI(a) memset(a,127,sizeof(a))
#define MEMi(a) memset(a,128,sizeof(a))
#define INF (2139062143)
#define phiF (1000000006)
#define MAXN (1000000+10)
typedef long long ll;
 
 
const int N=1500001;
struct intfo{ 
	int to,next;
} e[N<<1];
int n,m,i,x,y,cnt,f[N][2],first[N],d[N];
ll mo,g[N][2],b[N];
 
void add(int x,int y){
	e[++cnt].to=y; e[cnt].next=first[x]; first[x]=cnt;
}
 
void dp(int x,int fa){
	int t=0;
	ll s=1,p;
	g[x][0]=g[x][1]=1;
	for (int i=first[x];i;i=e[i].next)
		if (e[i].to!=fa){
			int y=e[i].to;
			dp(y,x);
			f[x][1]+=f[y][0];
			g[x][1]=(g[x][1]*g[y][0])%mo;
			f[x][0]+=f[y][0];
			s=(s*g[y][0])%mo;
		}
	m=0;
	for (int i=first[x];i;i=e[i].next)
		if (e[i].to!=fa) d[++m]=e[i].to;
	p=1;
	For (i,m){
		b[d[i]]=p;
		p=(p*g[d[i]][0])%mo;
	}
	p=1;
	ForD(i,m){
		b[d[i]]=(b[d[i]]*p)%mo;
		p=(p*g[d[i]][0])%mo;
		int y=d[i];
		if (f[y][1]-f[y][0]==t) s=(s+g[y][1]*b[y])%mo;
		else if (f[y][1]-f[y][0]>t){
			t=f[y][1]-f[y][0];
			s=(g[y][1]*b[y])%mo;
		}
	}
	f[x][1]++;
	f[x][0]+=t;
	g[x][0]=s;
}
 
int main()
{
	int size = 256 << 20;
    char *p = (char*)malloc(size) + size;
		scanf("%d",&n);
		For (i,n-1){
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		mo=1;
		dp(1,0);
		printf("%d\n",f[1][0]);
} 
#endif