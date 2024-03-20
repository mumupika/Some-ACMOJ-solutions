#if 0
#include<iostream>
using namespace std;
typedef long long ll;

const int MAXM = 1e4 + 5;
ll dp[MAXM];

void knapsack(int w, int v, int m, ll c)
{
    for (int k = 0; k <= 30 && c; k++)
    {
        if ((1 << k) > c)
        {
            continue;
        }
        ll s = (1 << k);
        c -= s;
        for (int j = m; j >= s * w; j--)
        {
            dp[j] = dp[j] > (dp[j - s * w] + s * v) ? dp[j] : (dp[j - s * w] + s * v);
        }
    }
    for (int j = m; j >= c * w; j--)
    {
        dp[j] = dp[j] > (dp[j - c * w] + c * v) ? dp[j] : (dp[j - c * w] + c * v);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int w, v;
    ll c;
    for (int i = 1; i <= n; i++)
    {
        cin >> w >> v >> c;
        knapsack(w, v, m, c);
    }
    cout << dp[m] << endl;
    return 0;
}
#endif