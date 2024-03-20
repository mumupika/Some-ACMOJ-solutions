#if 0
#include<iostream>
#include<stack>
#include<cstring>
#define ll long long
using namespace std;
/**
 * 哈夫曼节点的构建。
 * 利用数组进行存储，我们以下标的形式储存父节点和左右节点。
 * 权重存储。
*/
template<class T>
struct HuffmanNode
{
    T data;
    ll weight;
    ll parent;
    ll left,right;
};
/**
 * 寻找最小下标值。
 * 可以利用最小堆优化？
*/
template<class T>
int minIndex(HuffmanNode<T> bt[],int k,int m)
{
    ll i,min,minWeight=__LONG_LONG_MAX__;//将最小权重初始化成一个足够大的值。
    for(i=m-1;i>k;i--)//倒序查找直到传入的下标终止值：k，m为数组最后的存储之节点权重。
    {
        if(bt[i].parent==0 && bt[i].weight<minWeight)
        {
            min=i;
            minWeight=bt[min].weight;
        }
    }
    return min;
}
template<class T>
HuffmanNode<T>* BestBinaryTree(T a[],ll w[],ll n)
{
    HuffmanNode<T> *BBTree;
    ll first_min,second_min;
    ll m=n*2;//总共2n-1个节点。下标为0处不放节点。
    BBTree=new HuffmanNode<T> [m];
    ll i,j;
    //存储已经出现的节点，将他们从2n-1存放到n,并且赋予父节点和左右子节点为0的标记。
    for(j=0;j<n;j++)
    {
        i=m-1-j;
        BBTree[i].data=a[j];
        BBTree[i].weight=w[j];
        BBTree[i].parent=0,BBTree[i].left=0,BBTree[i].right=0;
    }
    i=n-1;//i是已经准备好第一个节点的位置。
    //接下来构建最优二叉树。
    while(i!=0)
    {
        //寻找第一小和第二小的值，并且记录下来该节点为它们父母之节点。
        first_min=minIndex(BBTree,i,m);
        BBTree[first_min].parent=i;
        second_min=minIndex(BBTree,i,m);
        BBTree[second_min].parent=i;
        //新节点的处理：1.父节点未知为0，2.
        BBTree[i].weight=BBTree[first_min].weight+BBTree[second_min].weight;
        BBTree[i].parent=0;
        BBTree[i].left=first_min,BBTree[i].right=second_min;
        i--;
    }
    return BBTree;
}
//进入哈夫曼编码部分。
template<class T>
char **HuffmanCode(HuffmanNode<T>BBTree[],int n)
{
    stack<char> s;
    char **HFCode;
    ll m,i,j,parent,child;
    //为HFCode创建空间,由于树最高为n，哈夫曼编码之最长长度即为n-1.
    HFCode=new char* [n];
    for(i=0;i<n;i++)
        HFCode[i]=new char[n+1];
    m=2*n;//BBTREE数组长度。
    if(n==0) return HFCode;//没有元素
    if(n==1) //n=1的情况，只有一个节点，编码为0.
    {
        HFCode[0][0]='0',HFCode[0][1]='\0';
        return HFCode;
    }
    //反向回溯至根节点并且将0，1字符存储于栈中，最后弹出。//可以利用递归？
    for(i=m-1;i>=n;i--)
    {
        child=i;
        parent=BBTree[child].parent;
        while(parent!=0)
        {
            if(BBTree[parent].left==child)//回溯至父节点，其子节点为左节点时，入栈‘0’。
                s.push('0');
            else
                s.push('1');
            child=parent;
            parent=BBTree[parent].parent;
        }
        j=0;
        while(!s.empty())
        {
            HFCode[m-i-1][j]=s.top();
            s.pop();
            j++;
        }
        HFCode[m-i-1][j]='\0';
    }
    return HFCode;
}
int main()
{
    ll n;
    scanf("%lld",&n);
    if(n==0)
    {
        cout << 0 << endl;
        return 0;
    }
    char *a=new char[n];
    ll *w=new ll[n];
    for(ll i=0;i<n;i++)
        scanf("%lld",&w[i]);
    if(n==1)
    {
        cout << w[0] << endl;
        return 0; 
    }
    HuffmanNode<char> *Tree;
    Tree=BestBinaryTree(a,w,n);
    char **HFCode;
    HFCode=HuffmanCode(Tree,n);
    //计算字符长度的加权和。
    ll res=0,m=2*n;
    for(ll i=0;i<n;i++)
        res+=strlen(HFCode[i])*w[i];
    cout << res << endl;
    return 0;
}
#endif