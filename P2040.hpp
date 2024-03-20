// n-ary tree to binary tree: "transform.cpp"
#ifndef NAryTree_To_BinaryTree
#define NAryTree_To_BinaryTree

#include "tree.hpp"

NAryTree::NAryTree(int v)
{
    val=v;
    children.resize(0);
}
BinaryTree::BinaryTree(int v)
{
    val=v;
    lson=nullptr;
    rson=nullptr;
}
NAryTree* NAryTree::BuildTree()
{
    int i=1;
    NAryTree *root=new NAryTree(i);
    queue<NAryTree*> q;
    q.push(root);

    NAryTree *pre,*temp;//pre is the parent of the node;temp for create new node;
    while(!q.empty())
    {
        pre=q.front();
        q.pop();
        //cin the children number and the children's code;
        int num;
        cout << "现在节点为：" << pre->val << ",请输入孩子的个数：";
        cin >> num;
        if(num==0) continue;
        for(int j=1;j<=num;j++)
        {
            temp=new NAryTree(++i);
            q.push(temp);
            pre->children.push_back(temp);
        }
    }
    cout << "建树完成。\n";
    return root;
}

BinaryTree* Transform(const NAryTree *node)
{
    BinaryTree* root=new BinaryTree(node->val);
    queue<BinaryTree*> store_1;
    queue<const NAryTree*> store_2;
    store_1.push(root);
    store_2.push(node);
    BinaryTree *pre,*temp;
    const NAryTree *temp_A;
    while(!store_1.empty())
    {
        pre=store_1.front();
        store_1.pop();
        temp_A=store_2.front();
        store_2.pop();
        //cout << "二叉树节点为" << pre->val << ";n叉树节点为" << temp_A->val << '\n';
        if(!temp_A->children.size()) continue;
        pre->lson=new BinaryTree(temp_A->children[0]->val);
        //cout << "二叉树节点" <<pre->val << "的左子节点: " << pre->lson->val << '\n';
        store_1.push(pre->lson);
        store_2.push(temp_A->children[0]);
        pre=pre->lson;
        for(int i=1;i<temp_A->children.size();i++)
        {
            pre->rson=new BinaryTree(temp_A->children[i]->val);
            //cout << "二叉树节点" << pre->val << "的右子节点: " << pre->rson->val << '\n';
            store_1.push(pre->rson);
            store_2.push(temp_A->children[i]);
            pre=pre->rson;
        }
    }
    return root;
}

#endif