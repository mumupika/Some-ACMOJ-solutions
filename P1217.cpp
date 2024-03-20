#if 0
#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;
int main()
{
    stack<long long> s1;
    stack<long long> s2;
    long long minx=3000000009;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int op;
        scanf("%d",&op);
        switch(op)
        {
            case 0:
                long long x;
                scanf("%lld",&x);
                s1.push(x);
                if(x<=minx)
                {
                    s2.push(x);
                    minx=x;
                }
                break;
            case 1:
                if(s1.empty())
                {
                    printf("Empty\n");
                }
                else if(s1.top()<=s2.top())
                {
                    s1.pop();
                    s2.pop();
                    if(s2.empty())
                    {
                        minx=3000000009;
                    }
                    else
                    {
                        minx=s2.top();
                    }
                }
                else
                {
                    s1.pop();
                }
                break;
            case 2:
                if(s1.empty())
                {
                    printf("Empty\n");
                }
                else
                    printf("%lld\n",s1.top());
                break;
            case 3:
                if(s1.empty())
                {
                    printf("Empty\n");
                    break;
                }
                else 
                    printf("%lld\n",s2.top());
                break;
        }
    }
}
#endif