#if 0
#include <iostream>
const int NMAX = 100005;

struct Node
{
    int value;
    Node *left, *right;
    Node(int _value = 0, Node *_left = nullptr, Node *_right = nullptr) : value(_value), left(_left), right(_right) {}
} *root = nullptr;

char answer[NMAX], operation[5];
int total, data, length;

bool search(Node *current, int value)
{
    if (current == nullptr)
        return false;
    if (value == current->value)
        return true;
    if (value < current->value)
    {
        answer[length++] = 'l';
        return search(current->left, value);
    }
    else
    {
        answer[length++] = 'r';
        return search(current->right, value);
    }
}

void insert(Node *&current, int value)
{
    if (current == nullptr)
        current = new Node(value);
    else if (value < current->value)
        insert(current->left, value);
    else if (value > current->value)
        insert(current->right, value);
}

void replace(Node *&current, int value)
{
    if (value < current->value)
        replace(current->left, value);
    else if (value > current->value)
        replace(current->right, value);
    else if (value == current->value)
    {
        Node *temp = current;
        current = current->right;
        delete temp;
    }
}

void remove(Node *&current, int value)
{
    if (current == nullptr)
        return;
    if (value < current->value)
        remove(current->left, value);
    else if (value > current->value)
        remove(current->right, value);
    else if (value == current->value)
    {
        if (current->right == nullptr)
        {
            Node *temp = current;
            current = current->left;
            delete temp;
        }
        else
        {
            Node *temp = current->right;
            while (temp->left != nullptr)
                temp = temp->left;
            current->value = temp->value;
            replace(current->right, temp->value);
        }
    }
}

void clear(Node *current)
{
    if (current == nullptr)
        return;
    clear(current->left);
    clear(current->right);
    delete current;
}

int main()
{
    scanf("%d", &total);
    for (int i = 1; i <= total; i++)
    {
        scanf("%s%d", operation, &data);
        if (operation[0] == '*')
        {
            length = 0;
            if (search(root, data))
            {
                answer[length] = '\0';
                printf("*%s\n", answer);
            }
            else
                printf("Nothing.\n");
        }
        else if (operation[0] == '+')
            insert(root, data);
        else if (operation[0] == '-')
            remove(root, data);
    }
    clear(root);
    return 0;
}
#endif//180ms
#if 0
#include<iostream>
using namespace std;
struct node{
    node *left;
    node *right;
    int value;
    node(int va=0,node *l=NULL,node*r=NULL){value=va;left=l;right=r;}
};
node *root=NULL;
void insert(int x,node *&rt)//指针的引用的目的->修改rt指向的内存区域时，root指向的区域也一起改动
{
    if(rt==NULL) {rt=new node(x);return;}
    if(x<rt->value) insert(x,rt->left);
    if(x>rt->value) insert(x,rt->right);
}
node* find(int x,node *&rt)
{
    if(rt==NULL) return NULL;
    if(rt->value==x) return rt;//先判断是否为NULL，调用空指针指向的元素会re
    if(x<rt->value) return find(x,rt->left);//含返回值的递归函数->注意递归参数传出
    if(x>rt->value) return find(x,rt->right);

}
void findd(int x,node *&rt)
{
    if(rt->value==x) {
        cout<<endl;
        return;
    }
    if(x<rt->value) {
        cout<<"l";
        findd(x,rt->left);
    }
    if(x>rt->value) {
        cout<<"r";
        findd(x,rt->right);
    }
}
void remove2(int x,node *&rt)
{
    if(x<rt->value) remove2(x,rt->left);
    if(x>rt->value) remove2(x,rt->right);
    if(x==rt->value){
        node *tmp=rt;
        rt=rt->right;//直接用右儿子替代
        delete tmp;
        return;
    }

}
void remove(int x,node *&rt)
{
    if(rt==NULL) return;//没有找到该节点
    if(x<rt->value) remove(x,rt->left);
    if(x>rt->value) remove(x,rt->right);
    if(x==rt->value)
    {
        if(rt->right==NULL) {
            node *tmp=rt;
            rt=rt->left;
            delete tmp;
        }
        else{
            node *tmp=rt->right;
            while(tmp->left!=NULL){
                tmp=tmp->left;
            }
            rt->value=tmp->value;//链接的逻辑关系不改变，只更换值（有两个儿子时）
            remove2(tmp->value,rt->right);//为什么从rt开始递归->保证与父亲节点的关系
        }
    }
}

int main()
{
    int q;cin>>q;
    for(int i=0;i<q;i++)
    {
        char op;int x;
        cin>>op>>x;
        if(op=='+') insert(x,root);
        if(op=='-') remove(x,root);
        if(op=='*') {
            node *p=find(x,root);
            if(p==NULL) {
                cout<<"Nothing."<<endl;
                continue;
            }
            cout<<"*";
            findd(x,root);
        }
    }
}
#endif//508ms