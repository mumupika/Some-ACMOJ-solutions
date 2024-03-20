#if 0
#include<iostream>
#include<stack>
#define ll long long
const ll MAXN=1000005;
ll target[MAXN];
using namespace std;
int main()
{
    int line;
    scanf("%d",&line);
    for(int i=0;i<line;i++)
    {
        int number;
        scanf("%d",&number);
        stack<int> s;
        int a=1,b=1;
        for(int j=1;j<=number;j++)
           scanf("%lld",&target[j]);
        int flag=1;
        while(b<=number)
        {
            if(a==target[b]) a++,b++;
            else if(!s.empty() && s.top()==target[b]) s.pop(),b++;
            else if(a<=number) s.push(a++);
            else 
            {
                flag=0;break;
            }
        }
        printf("%s\n",flag?"Yes":"No");
    }
    return 0;
}
#endif