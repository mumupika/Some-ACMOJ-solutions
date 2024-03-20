#if 0
#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 55
#define MAX_M 2510

struct edge_t {
    int v, next;
    bool vis;
} edge[4 * MAX_M];
int head[MAX_M], x[MAX_M], y[MAX_M];
int cur_edge = 1;

void add_edge(int u, int v) {
    edge[++cur_edge].v = v;
    edge[cur_edge].next = head[u];
    edge[cur_edge].vis = false;
    head[u] = cur_edge;
    
    edge[++cur_edge].v = u;
    edge[cur_edge].next = head[v];
    edge[cur_edge].vis = false;
    head[v] = cur_edge;
}

int n, m;
char map[MAX_N][MAX_N];
int block[MAX_N][MAX_N];

void bfs1(int i, int j, int k) {
    queue<int> q;
    q.push(i); q.push(j);
    block[i][j] = k;
    while (!q.empty()) {
        int i = q.front(); q.pop();
        int j = q.front(); q.pop();
        if (i < n - 1 && map[i + 1][j] == '.' && !block[i + 1][j]) {
            q.push(i + 1), q.push(j);
            block[i + 1][j] = k;
        }
        if (i > 0 && map[i - 1][j] == '.' && !block[i - 1][j]) {
            q.push(i - 1), q.push(j);
            block[i - 1][j] = k;
        }
        if (j < m - 1 && map[i][j + 1] == '.' && !block[i][j + 1]) {
            q.push(i), q.push(j + 1);
            block[i][j + 1] = k;
        }
        if (j > 0 && map[i][j - 1] == '.' && !block[i][j - 1]) {
            q.push(i), q.push(j - 1);
            block[i][j - 1] = k;
        }
    }
}

bool vis[MAX_M];
int bfs2(int i, int k) {
    if (map[x[i]][y[i]] == '?') return 1;
    queue<int> q;
    q.push(i);
    vis[i] = true;
    bool amb = false;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        int edge_cnt = 0;
        for (int e = head[cur]; e; e = edge[e].next, ++edge_cnt) {
            if (vis[edge[e].v]) continue;
            q.push(edge[e].v);
            vis[edge[e].v] = true;
            edge[e].vis = edge[e ^ 1].vis = true;
        }
        if (map[x[cur]][y[cur]] == '?') {
            if (edge_cnt == 1) amb = true;
            map[x[cur]][y[cur]] = '.';
        }
    }
    for (int i = 1; i < k; ++i) {
        if (map[x[i]][y[i]] != '?' && !vis[i]) return -1;
    }
    for (int i = 1; i < k; ++i) {
        if (map[x[i]][y[i]] != '.') continue;
        for (int e = head[i]; e; e = edge[e].next) {
            if (!edge[e].vis) return 1;
        }
    }
    return amb ? 1 : 0;
}

int main() {
    cin >> n >> m;
    // input map
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }
    // search connected block
    int k = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == '.' && !block[i][j]) {
                x[k] = i; y[k] = j;
                bfs1(i, j, k++);
            }
        }
    }
    // build graph
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == '?') {
                x[k] = i; y[k] = j;
                block[i][j] = k++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == '?') {
                #define COND(i1, j1) block[i1][j1] ? (map[i1][j1] == '?' && block[i1][j1] < block[i][j] ? 0 : block[i1][j1]) : 0
                int con[4] = {
                    i < n - 1 && COND(i + 1, j),
                    i > 0 && COND(i - 1, j),
                    j < m - 1 && COND(i, j + 1),
                    j > 0 && COND(i, j - 1)
                };
                #undef COND
                if (con[0]) add_edge(block[i][j], con[0]);
                if (con[1] && con[1] != con[0]) add_edge(block[i][j], con[1]);
                if (con[2] && con[2] != con[1] && con[2] != con[0]) add_edge(block[i][j], con[2]);
                if (con[3] && con[3] != con[2] && con[3] != con[1] && con[3] != con[0]) add_edge(block[i][j], con[3]);
            }
        }
    }
    // search
    int ans = bfs2(1, k);
    if (ans == 1) cout << "Ambiguous" << endl;
    else if (ans == -1) cout << "Impossible" << endl;
    else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) cout << (map[i][j] == '?' ? '#' : map[i][j]);
            cout << endl;
        }
    }
    return 0;
}
#endif