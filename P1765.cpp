#if 0
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int MAXN = 1000005;
int n, cb, cc;
char s[10*MAXN];
struct node {
    int l, r, id;
    node(){}
    node(int l, int r, int id):l(l), r(r), id(id){}
    //bool operator <(const node &o)const {
    //    return l-r > o.l-o.r || (l-r == o.l-o.r && l > o.l) || (l-r==o.l-o.r && l==o.l && id<o.id);
    //}
}a[MAXN], b[MAXN], c[MAXN];
//set<node>myset;
int ans[MAXN];// bool vis[MAXN];
bool cmp1(node A, node B) {
    return A.l < B.l || (A.l == B.l && A.r > B.r);
}
bool cmp2(node A, node B) {
    return A.r > B.r || (A.r == B.r && A.l > B.l);
}
/*
void doit(int &now, int x, int &i) {
    set<node>::iterator it, it2; node t;
    while(x) {
        it = myset.lower_bound(node(x, 10000005, 0));
        if(it != myset.end()) {
            while(it != myset.end() && vis[(*it).id]) {
                it2 = it; ++it; myset.erase(it2);
            }
            if(it != myset.end()) {
                t = *it; vis[t.id] = 1;
                ans[i++] = t.id;
                now += t.r - t.l;
                x += t.r - t.l;
                myset.erase(it);
            }
            else return;
        }
        else return;
    }
}*/
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%s", s+1); a[i].id = i;
        int len = strlen(s+1);
        for(int j = 1; j <= len; ++j) {
            if(s[j] == '(') ++a[i].r;
            else {
                if(!a[i].r) ++a[i].l;
                else --a[i].r;
            }
        }
        //printf("[%d]: %d %d\n", i, a[i].l, a[i].r);
        //myset.insert(a[i]);
        if(a[i].r >= a[i].l) b[++cb] = a[i];
        else {
                c[++cc] = a[i];
                //myset.insert(a[i]);
        }
    }
    sort(b + 1, b + cb + 1, cmp1);
    sort(c + 1, c + cc + 1, cmp2);
    int i = 1, now = 0;
    for(int j = 1; j <= cb; ++j) {
        if(now >= b[j].l) {
            ans[i++] = b[j].id;
            now += b[j].r-b[j].l;
        }
        else break;
    }
    if(i <= cb) {
        puts("impossible");
        return 0;
    }
    for(int j = 1; j <= cc; ++j) {
        if(now >= c[j].l) {
            ans[i++] = c[j].id;
            now += c[j].r-c[j].l;
        }
        else break;
    }
    /*for(int j = 1; j <= cc; ++j) if(!vis[c[j].id]) {
        vis[c[j].id] = 1;
        if(now >= c[j].l) {
            doit(now, now-c[j].l, i);
            ans[i++] = c[j].id;
            now += c[j].r-c[j].l;
        }
        else break;
    }*/
    if(i <= n || now != 0) puts("impossible");
    else {
        for(int j = 1; j <= n; ++j)
            printf("%d\n", ans[j]);
    }
}
#endif