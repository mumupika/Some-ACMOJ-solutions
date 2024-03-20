#if 0
#include <iostream>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;
int a[MAXN]{}, dp[MAXN]{}, val[MAXN]{};
int n;

int fastfind(int tar, int n)
{
    int l = 1, r = n;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (val[m] > a[tar])
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    return l;
}

void Init()
{
    cin >> n;
    for (int i = 0; i < MAXN; i++)
    {
        val[i] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

int main() 
{
    Init();
    int tmp;
    for (int i = 1; i <= n; i++)
    {
        tmp = fastfind(i, n);
        val[tmp] = a[i];
        dp[i] = tmp;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    return 0;
}
#endif