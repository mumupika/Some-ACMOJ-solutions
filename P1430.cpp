#if 0
#include<iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 400;
int n, m, x, s, t, a;
vector<pair<int, int> >e[MAXN];
ll f[MAXN][MAXN];

void Init()
{
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++)
    {
        cin >> s >> t >> a;
        e[s - 1].push_back(pair<int, int>(t, a));
    }
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            f[i][j] = -1;
        }
    }
}

void Greedy()
{
    f[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (f[i][j] >= 0)
            {
                f[i + 1][j] = f[i + 1][j] > f[i][j] ? f[i + 1][j] : f[i][j];
                f[i + 1][j + 1] = f[i + 1][j + 1] > (f[i][j] - x) ? f[i + 1][j + 1] : (f[i][j] - x);
                for (int k = 0; k < e[i].size(); k++)
                {
                    f[e[i][k].first][j] = f[e[i][k].first][j] > (f[i][j] + e[i][k].second) ? f[e[i][k].first][j] : (f[i][j] + e[i][k].second);
                }
            }
        }
    }
}

int main()
{
    Init();
    Greedy();
    for (int i = n; i >= 0; i--)
    {
        if (f[n][i] >= 0)
        {
            cout << f[n][i] << endl;
            return 0;
        }
    }
}
#endif
#if 0
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 370;
int n, m, x;
vector<pair<int,int> >e[MAXN];
long long f[MAXN][MAXN];
int main() {
    memset(f, -1, sizeof f);
    scanf("%d%d%d", &n, &m, &x);
    for(int i = 1, s, t, a; i <= m; ++i)
        scanf("%d%d%d", &s, &t, &a), e[s-1].push_back(pair<int,int>(t, a));
    f[0][0] = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j <= i; ++j)
            if(f[i][j] >= 0) {
                f[i+1][j] = max(f[i+1][j], f[i][j]);
                f[i+1][j+1] = max(f[i+1][j+1], f[i][j]-x);
                for(int siz = e[i].size(), k = 0; k < siz; ++k)
                    f[e[i][k].first][j] = max(f[e[i][k].first][j], f[i][j] + e[i][k].second);
            }
    for(int j = n; ; --j) if(f[n][j] >= 0)
    {
        //printf("%d$\n", j);
            printf("%lld\n", f[n][j]); return 0;
    }
}
#endif