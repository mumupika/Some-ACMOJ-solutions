#if 0
#include<iostream>
using namespace std;
struct node 
{
    char data;
    int left;
    int count;
    int right;
};
node tree1[30],tree2[30];
int build(node tree[]) // 创建树。
{
    int n;
    scanf("%d",&n);
    string a, b;
    int x, y;
    bool* son = new bool [30];
    for (int i = 0 ; i < 30 ; ++i) 
        son[i] = false;
    for (int i = 0 ; i < n ; ++i) 
    {
        cin >> tree[i].data >> a >> b;
        if (a != "-") 
        {
            x = stoi(a);//stoi:将string->int;
            tree[i].left = x;
            tree[i].count++;
            son[x] = true;
        }
        else tree[i].left = -1;

        if (b != "-") 
        {
            y = stoi(b);
            tree[i].right = y;
            tree[i].count++;
            son[y] = true;
        }
        else tree[i].right = -1;
    }

    for (int i = 0 ; i < n ; ++i)
        if (!son[i]) return i;
    return -1;
}
bool check(int a, int b) 
{
    if (a == -1 && b == -1) return true;
    if (a != -1 && b == -1) return false;
    if (a == -1 && b != -1) return false;
    if (tree1[a].data != tree2[b].data) return false;
    if (tree1[a].count != tree2[b].count ) return false;

    if (tree1[a].count == 0) return true;
    else if (tree1[a].count == 1) 
    {
        if (tree1[a].left == -1)
        {
            if (tree2[b].left == -1) 
                return check(tree1[a].left, tree2[b].left) && check(tree1[a].right, tree2[b].right);
            else 
                return check(tree1[a].left, tree2[b].right) && check(tree1[a].right, tree2[b].left);
        }
        else
        {
            if (tree2[b].right == -1) 
                return check(tree1[a].left, tree2[b].left) && check(tree1[a].right, tree2[b].right);
            else 
                return check(tree1[a].left, tree2[b].right) && check(tree1[a].right, tree2[b].left);
        }
    }
    else if (tree1[a].count == 2) 
    {
        if (tree1[tree1[a].left].data == tree2[tree2[b].left].data)
            return check(tree1[a].left, tree2[b].left) && check(tree1[a].right, tree2[b].right);
        else if (tree1[tree1[a].left].data == tree2[tree2[b].right].data)
            return check(tree1[a].left, tree2[b].right) && check(tree1[a].right, tree2[b].left);
        else 
            return false;
    }
    return false;
}
int main() 
{
    int a, b;
    a = build(tree1);
    b = build(tree2);
    if (check(a, b)) printf("Yes");
    else printf("No");
    return 0;
}
#endif