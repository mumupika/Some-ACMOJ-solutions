/**
 * References:
 * https://zhuanlan.zhihu.com/p/669535536
 * https://acm.sjtu.edu.cn/OnlineJudge/code/360792/
*/
#if 0
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 21, M = (1 << 21);
int n;
int w[N][N];//w表示两点之间的距离
int f[M][N];//M表示状态，一共最多二十位
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    //处理输入
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin >> w[i][j];
    
    //先将所有的变量初始化为正无穷
    memset(f, 0x3f3f3f3f, sizeof(f));
    //初始化，从第0个点走到第0个点
    f[1][0] = 0;
    
    //预处理
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                w[i][j]=min(w[i][k]+w[k][j],w[i][j]);

    //开始计算从状态0开始枚举
    for(int i=1;i<(1 << n);i++)
    {
        for(int j=0; j<n;j++)
        {
            for(int k=0; k<n; k++)
            {
                if(!(i & (1<<k))) continue;//访问过的城市，过。
                f[i|(1<<j)][j]=min(f[i|(1<<j)][j],f[i][k]+w[k][j]);
            }
        }
    }                    
    // (1<<n) - 1即2^n - 1，表示从0到n - 1个点全都走了一遍
    int res=0x3f3f3f3f;
    for(int i=0;i<n;i++) 
        res=min(res,f[(1<<n)-1][i]+w[i][0]);
    cout << res;
    return 0;
}
#endif