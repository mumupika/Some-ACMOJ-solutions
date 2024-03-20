#if 0
#include<iostream>
#include<algorithm>
using namespace std;
class Node
{
    public:
       int *parent;
       int *left;
       int *right;
       int sign;
       Node(){parent=nullptr;left=nullptr;right=nullptr;sign=0;}
};
int main()
{
    int n;
    scanf("%d",&n);
    Node *tree=new Node [n];
    int x,maxNum=0;
    for (int i=1;i<n;i++)
    {
        cin>>x;
        if (tree[x].left==nullptr)
        {
            tree[i].parent=tree[x].left;
            tree[i].sign=2*tree[x].sign+1;
            maxNum=max(maxNum,tree[i].sign);
        }
        else 
        {
            tree[i].parent=tree[x].right;
            tree[i].sign=2*tree[x].sign+2;
            maxNum=max(maxNum,tree[i].sign);
        }
    }
    if (maxNum>=n)
    {
        printf("false");
    }
    else printf("true");
    return 0;
}
#endif