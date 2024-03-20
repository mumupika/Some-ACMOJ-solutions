#if 0
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
struct Node
{
    ll number;
    ll strength;
    ll score;
};
bool cmp(Node &a,Node &b)
{
    if(a.score==b.score)
        return a.number<b.number;
    return a.score>b.score;
}
int main()
{
    ll N,R,num=1;
    scanf("%lld%lld",&N,&R);
    Node *mice=new Node[2*N];
    for(int i=0;i<2*N;i++)
    {
        mice[i].number=num++;
        scanf("%lld",&mice[i].score);
    }
    for(int i=0;i<2*N;i++)
        scanf("%lld",&mice[i].strength);
    sort(mice,mice+2*N,cmp);
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<2*N-1;j+=2)
        {
            if(mice[j].strength<mice[j+1].strength)
            {
                mice[j+1].score+=2;
            }
            else if(mice[j].strength==mice[j+1].strength)
            {
                mice[j+1].score++;
                mice[j].score++;
            }
            else
            {
                mice[j].score+=2;
            }
        }
        sort(mice,mice+2*N,cmp);
    }
    for(int i=0;i<2*N;i++)
        printf("%lld ",mice[i].number);
    delete []mice;
    return 0;
}
#endif