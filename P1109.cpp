#if 0
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
#define ll long long
const ll MAXN=1000005;
char a[MAXN];
ll *b;
ll cnt=0;
string temp="";
struct node
{
    ll data;
    node *left,*right;
    node(ll a){data=a;left=nullptr;right=nullptr;}
    node(){left=nullptr,right=nullptr;}
};
class BinaryTree
{
    node* root;
    public:
    BinaryTree(){root=nullptr;}
    void create_the_tree();
    node* Root(){return root;}
    void InOrder();
    void PostOrder();
    //减少时间则删去以下函数。
    //void DelTree(node*);//
    //~BinaryTree(){DelTree(root);}//
};
/*
void BinaryTree::DelTree(node* thisRoot)//
{
    if(!thisRoot) return;
    DelTree(thisRoot->left);
    DelTree(thisRoot->right);
    delete thisRoot;
}
*/
void BinaryTree::create_the_tree()
{
    int i=0;
    ll tmp;
    node* p;
    if(a[0]=='.') {root=nullptr;return;}
    while(a[i]!=' ')
    {
        temp+=a[i];
        i++;
    }
    tmp=stoi(temp);
    temp="";
    p=new node(tmp);
    root=p;
    stack<node*> n;
    stack<int> s;
    n.push(p);
    s.push(0);
    i++;
    while(a[i]!='\0')
    {
        if(a[i]==' ')
        {
            i++;
            continue;
        }
        else if(a[i]!='.' && s.top()==0 && a[i]!=' ')
        {
            while(a[i]!=' ')
            {
                temp+=a[i];
                i++;
            }
            tmp=stoi(temp);
            temp="";//转换字符串成数字，并归零。
            p->left=new node(tmp);
            s.top()=1;
            n.push(p->left);
            s.push(0);
            p=p->left;
            i++;
        }
        else if(a[i]=='.' && s.top()==0 && a[i]!=' ')
        {
            p->left=nullptr;
            s.top()=1;
            i++;
        }
        else if(a[i]!='.' && s.top()==1 && a[i]!=' ')
        {
            while(a[i]!=' ')
            {
                temp+=a[i];
                i++;
            }
            tmp=stoi(temp);
            temp="";//转换字符串成数字，并归零。
            p->right=new node(tmp);
            n.push(p->right);
            s.top()=2;
            s.push(0);
            p=p->right;
            i++;
        }
        else if(a[i]=='.' && s.top()==1 && a[i]!=' ')
        {
            p->right=nullptr;
            s.top()=2;
            i++;
        }
        else if(s.top()==2)
        {
            n.pop();
            s.pop();
            p=n.top();
        }
    }
}
void BinaryTree::PostOrder()
{
    if(!root) return;
    stack<node*> elementStack;
    stack<int> elementSign;
    node* p;
    elementStack.push(root);elementSign.push(0);
    while(!elementStack.empty())
    {
        switch(elementSign.top())
        {
            case 0:
                p=elementStack.top();
                if(p->left)
                {
                    elementStack.push(p->left);
                    elementSign.pop();
                    elementSign.push(1);
                    elementSign.push(0);
                }
                else
                {
                    elementSign.pop();
                    elementSign.push(1);
                }
                break;
            case 1:
                p=elementStack.top();
                if(p->right)
                {
                    elementStack.push(p->right);
                    elementSign.pop();
                    elementSign.push(2);
                    elementSign.push(0);
                }
                else
                {
                    elementSign.pop();
                    elementSign.push(2);
                }
                break;
            case 2:
                p=elementStack.top();
                //cout << p->data << ' ';
                printf("%lld ",p->data);
                elementStack.pop();
                elementSign.pop();
                break;
        }
    }
    printf("\n");
}
void BinaryTree::InOrder()
{
    if(!root) return;
    stack<node*> elementStack;//储存元素的栈
    stack<int> elementSign;//储存标识符，以用于判断是否出栈。
    node* p=root;
    int flag;
    elementStack.push(p);elementSign.push(0);//刚开始，标记为0.
    while(!elementStack.empty())
    {
        flag=elementSign.top();
        elementSign.pop();
        p=elementStack.top();//准备更换栈底标识符。
        if(flag == 1)
        {
            elementStack.pop();//当进行模拟（寻找左节点为空）
            printf("%lld ",p->data);
            //cout << p->data << ' ';
            if(!p->right) continue;//有右节点就压入右节点，反之继续循环。
            elementStack.push(p->right);
            elementSign.push(0);
        }
        else//栈顶标识符为0，不输出，继续压栈。
        {
            elementSign.push(1);//改变被压住的元素标识符。
            if(p->left)
            {
                elementStack.push(p->left);
                elementSign.push(0);
            }
        }
    }
    printf("\n");
}
int main()
{
    cin.getline(a,1000005,'\n');
    BinaryTree tree;
    tree.create_the_tree();
    tree.InOrder();
    tree.PostOrder();
    return 0;
}
#endif