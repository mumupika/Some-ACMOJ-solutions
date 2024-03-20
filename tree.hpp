#ifndef TREE_HPP
#define TREE_HPP
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct NAryTree
{
	int val;
	vector<NAryTree*> children;
    NAryTree(int);
    NAryTree* BuildTree();
};
struct BinaryTree
{
	int val;
	BinaryTree *lson,*rson;
    BinaryTree(int);
};
#endif