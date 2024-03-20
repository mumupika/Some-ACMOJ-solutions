#if 0
#include <cstdio>
#include <algorithm>
const int NMAX = 1505, INF = 0x3f3f3f3f;

int f[NMAX][NMAX], n, m, r = 0;
char s[NMAX][NMAX];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f[i][j] = (s[i][j] == 'X' ? 0 : f[i][j - 1] + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (f[i][j] >= 2)
            {
                int p = INF, l = std::max(1, i - f[i][j] / 2 + 1);
                for (int k = i; k >= l; k--)
                {
                    p = std::min(p, f[k][j]);
                    r = std::max(r, std::min(p / 2, i - k + 1));
                }
            }
    printf("%d\n", 2 * r * r);
    return 0;
}
#endif
//P1008
