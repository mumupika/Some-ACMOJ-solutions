#if 0
#include<iostream>
#include<queue>
#include<stack>
#define ll long long
using namespace std;
int main()
{
    stack<ll> store;
    stack<ll> tmp;
    stack<ll> comp;
    int num;
    ll temp;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scanf("%lld",&temp);
        tmp.push(temp);
    }
    while(!tmp.empty())
    {
        store.push(tmp.top());
        tmp.pop();
    }
    scanf("%d",&num);
    ll count=0;
    ll com;
    bool flag=true;
    for(int i=0;i<num;i++)
    {
        flag=true;
        scanf("%lld",&com);
        while(!store.empty() && flag)
        {
            temp=store.top();
            if(temp!=com)
            {
                comp.push(temp);
                store.pop();
                count++;
                continue;
            }
            else if(temp==com)
            {
                count++;
                store.pop();
                while(!comp.empty())
                {
                    store.push(comp.top());
                    comp.pop();
                }
                store.push(temp);
                flag=false;
            }
        }
        while(!comp.empty())
        {
            store.push(comp.top());
            comp.pop();
        }
    }
    printf("%lld",count);
    return 0;
}
#endif//2903ms
#if 0
#include<iostream>
using namespace std;
#define ll long long
struct node
{
    ll val;
    node* next;
    node(ll i){val=i;next=nullptr;}
    node(){val=0;next=nullptr;}
};
int main()
{
    node *head1,*head,*tmp,*r;
    ll temp,size;
    scanf("%lld",&size);
    scanf("%lld",&temp);
    head1=new node;
    head=new node(temp);
    head1->next=head;
    r=head;
    for(int i=1;i<size;i++)
    {
        tmp=new node;
        scanf("%lld",&temp);
        tmp->val=temp;
        r->next=tmp;
        r=tmp;
    }
    ll number,count=0,cmp;
    scanf("%lld",&number);
    for(int i=0;i<number;i++)
    {
        node *read=head,*pre=head1;
        scanf("%lld",&cmp);
        while(read && cmp!=read->val)
        {
            count++;
            read=read->next;
            pre=pre->next;
        }
        if(!read) continue;
        if(cmp==read->val)
        {
            count++;
            if(cmp==head->val) continue;
            node *tar=new node(cmp);
            pre->next=read->next;
            delete read;
            head1->next=tar;
            tar->next=head;
            head=tar;
        }
    }
    printf("%lld",count);
    return 0;
}
#endif//1467ms
#if 0
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,a;
    scanf("%d",&n);
    vector<int> arr;
    vector<int>::iterator it = arr.begin();
    for(int i =0;i < n; ++i)
    {
        scanf("%d",&a);
        arr.push_back(a);
    }
    int m,dest,res=0,len=0;
    scanf("%d",&m);
    for(int i =0; i< m; ++i)
    {
        scanf("%d",&dest);
        it = find(arr.begin(), arr.end(), dest);
        if(it != arr.end())
        {
            len = it - arr.begin();
            res += len +1;
            arr.erase(it);
            arr.insert(arr.begin(), dest);
        }
        else res += n;
    }
    printf("%d",res);
    return 0;
}
#endif//295ms