#if 0
//YES ! zxd ! YES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e6 + 100;
int fst[maxn],cnt,nxt[maxn << 1],n,m,u,v,a,b,ans[maxn],vis[maxn];
int low[maxn],inst[maxn],dfn[maxn],scc,col[maxn],st[maxn << 2],tail = -1,tnt;
struct edge{
    int u,v;
}side[maxn << 1];
void add(int u,int v) {
    side[++cnt] = {u,v};
    nxt[cnt] = fst[u];
    fst[u] = cnt;
}
void tarjan(int u) {
    low[u] = dfn[u] = ++tnt;
    st[++tail] = u;inst[u] = 1;
    for(int i = fst[u]; i; i = nxt[i]) {
        int v = side[i].v;
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        } else if(inst[v])
            low[u] = min(low[u],dfn[v]);
    }
    if(dfn[u] == low[u]) {
        ++scc;
        while(st[tail + 1] != u) {
            int v = st[tail--];
            col[v] = scc;
            inst[v] = 0;
        }
    }
} 
int main() {
    //fileopen;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        scanf("%d%d%d%d",&u,&a,&v,&b);
        if(a + b == 0) {
            add(2 * u + 1,2 * v);
            add(2 * v + 1,2 * u);
        } else if(a + b == 1) {
            if(a == 1) {
                add(2 * u,2 * v);
                add(2 * v + 1,2 * u + 1);
            } else {
                add(2 * u + 1,2 * v + 1);
                add(2 * v,2 * u);
            }
        } else {
            add(2 * v,2 * u + 1);
            add(2 * u,2 * v + 1);
        }
    }
    for(int i = 2; i <= 2 * n + 1; ++i)
        if(!dfn[i]) tarjan(i);
    for(int i = 2; i <= 2 * n + 1; i += 2) {
        if(col[i] == col[i + 1]) {
            printf("No");return 0;
        }
    }
    printf("Yes\n");
    for(int i = 2; i <= 2 * n + 1; i += 2) {
        if(vis[col[i]]) {
            ans[i >> 1] = 0;continue;
        }
        if(vis[col[i + 1]]) {
            ans[i >> 1] = 1;continue;
        }
        if(col[i] < col[i + 1]) {
            ans[i >> 1] = 0;
            vis[col[i]] = 1;
        } else {
            ans[i >> 1] = 1;
            vis[col[i + 1]] = 1;
        }
    }
    for(int i = 1; i <= n; ++i)
        printf("%d ",ans[i]);
    return 0;
}
#endif
#if 0
#include<bits/stdc++.h>
using namespace std;

template<class T>
void read(T &x){
    x = 0;
    bool neg = false;
    char chr = getchar();
    while (chr<'0'||chr>'9') neg|=(chr=='-'), chr=getchar();
    while (chr>='0'&&chr<='9') x = (x<<3)+(x<<1)+chr-'0', chr=getchar();
    x = neg?-x:x;
}

template<class T, class ...Args>
void read(T &arg, Args &...args){
    read(arg);
    read(args...);
}

const int MAXN = 1e6+5;
int n, m, edgecnt, cnt, color;
struct Edge{int to, nxt;};
Edge e[MAXN<<2];
int h[MAXN<<1];
int dfn[MAXN<<1], low[MAXN<<1], scc[MAXN<<1];
bool inStack[MAXN<<1];
stack<int> s;

void addEdge(int u, int v){
    e[++edgecnt] = Edge{v, h[u]};
    h[u] = edgecnt;
}

void tarjan(int u){
    dfn[u] = ++cnt;
    low[u] = dfn[u];
    s.push(u);
    inStack[u] = 1;
    for (int i=h[u];i;i=e[i].nxt){
        int v = e[i].to;
        if (!dfn[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v]) low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u]==low[u]){
        ++color;
        while (s.top()!=u){
            int tmp = s.top();
            s.pop();
            inStack[tmp] = 0;
            scc[tmp] = color;
        }
        s.pop();
        inStack[u] = 0;
        scc[u] = color;
    }
}

bool sat(){
    for (int i=1;i<=(n<<1);++i) if (!dfn[i]) tarjan(i);
    for (int i=1;i<=n;++i) if (scc[i]==scc[i+n]) return 0;
    return 1;
}

int main(){
    read(n, m);
    for (int i=1;i<=m;++i){
        int x, a, y, b;
        read(x, a, y, b);
        addEdge(a?x:x+n, b?y+n:y);
        addEdge(b?y:y+n, a?x+n:x);
    }
    bool flag = sat();
    if (!flag){
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for (int i=1;i<=n;++i) printf("%d ", scc[i]>scc[i+n]?1:0);
    return 0;
}
#endif
#if 0
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
//#define int lont long

inline void read(int &tmp) {
    char ch;
    while(!isdigit(ch = getchar()));
    tmp = 0;
    do {
        tmp = 10 * tmp + (ch ^ '0');
        ch = getchar();
    } while(isdigit(ch));
}


int n,m;
const int N = 1e6 + 10;
struct edge{int to,nxt;}e[N << 1];
int head[N << 1],cnt;
inline void adde(int fr,int to) {
    e[++cnt] = (edge){to,head[fr]};
    head[fr] = cnt;
}


int dfn[N << 1],low[N << 1],tot;
int scc[N << 1],top;
// bool vis[N << 1]; // in vector or not
vector <int> vec;
void tarjan(int u) {
    dfn[u] = low[u] = ++tot;
    vec.push_back(u);
    // vis[u] = true;
    for(int i = head[u] ; i ; i = e[i].nxt) {
        int v = e[i].to;
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        } else if(!scc[v]) {low[u] = min(low[u],dfn[v]);}
    }
    if(low[u] == dfn[u]) {
        ++top;
        do {
            scc[u] = top;
            u = vec.back();
            vec.pop_back();
            // vis[u] = false;
        } while(low[u] != dfn[u]);
    }
}



signed main() {
    read(n);
    read(m);
    vec.reserve(n << 1);
    while(m--) {
        int a,b,c,d;
        read(a);
        read(b);
        read(c);
        read(d);
        adde(a << 1 ^ b ^ 1,c << 1 ^ d);
        adde(c << 1 ^ d ^ 1,a << 1 ^ b);
    }
    // 2 ~ 2n + 1
    for(int i = 2 ; i <= (n << 1 | 1) ; ++i) {
        if(!dfn[i]) tarjan(i);
    }
    for(int i = 1 ; i <= n ; ++i) {
        if(scc[i << 1] == scc[i << 1 | 1]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes\n";
    for(int i = 1 ; i <= n ; ++i) {
        putchar((scc[i << 1 ] > scc[i << 1 | 1]) ^ '0');putchar(' ');
    }
    return 0;
}
#endif