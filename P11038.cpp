#if 0
/**1.模拟法*/
#include <iostream>
using namespace std;

int front[10000+10];
int nex[10000+10];
void out(int x){
    nex[front[x]] = nex[x];
    front[nex[x]] = front[x];
}

int main()
{
    int M;
    cin>>M;
    for (int i = 1; i <= M; ++i)
    {
        front[i] = (i==1) ? M : i-1;
        nex[i] = (i==M) ? 1 : i+1;
    }
    int cur = 1;
    int cnt = M;
    int K;
    while(1){
        cin>>K;
        K %= (cnt);
        if(K==0)
            K+=cnt;
        for (int i = 0; i < K-1; ++i)
        {
            cur = nex[cur];
        }
        out(cur);
        cur = nex[cur];
        cnt--;
        if(cnt == 1){
            cout<<cur<<endl;
            break;
        }
    }

    return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;

int front[10000+10];
int nex[10000+10];
void out(int x){
    nex[front[x]] = nex[x];
    front[nex[x]] = front[x];
}

int main()
{
    int M;
    cin>>M;
    for (int i = 1; i <= M; ++i)
    {
        front[i] = (i==1) ? M : i-1;
        nex[i] = (i==M) ? 1 : i+1;
    }
    int cur = 1;
    int cnt = M;
    int K;
    while(1){
        cin>>K;
        K %= (cnt);
        if(K==0)
            K+=cnt;
        for (int i = 0; i < K-1; ++i)
        {
            cur = nex[cur];
        }
        out(cur);
        cur = nex[cur];
        cnt--;
        if(cnt == 1){
            cout<<cur<<endl;
            break;
        }
    }

    return 0;
}
#endif