/*
Given two binary trees and imagine that when you put one of them to cover the other, 
some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, 
then sum node values up as the new value of the merged node. Otherwise, the NOT null node 
will be used as the node of new tree.

Example 1:

Input: 

	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7


Note: The merging process must start from the root nodes of both trees.

*/


#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL && t2==NULL)
            return NULL;
        TreeNode* t = new TreeNode(0);
        if(t1==NULL){
            t->val = t2->val;
            t->left = mergeTrees(NULL, t2->left);
            t->right = mergeTrees(NULL, t2->right);
            cout<<t->val<<endl;
        }
        else if(t2==NULL){
            t->val = t1->val;
            t->left = mergeTrees(t1->left, NULL);
            t->right = mergeTrees(t1->right, NULL);
            cout<<t->val<<endl;
        }
        else{
            t->val = t1->val + t2->val;
            t->left = mergeTrees(t1->left, t2->left);
            t->right = mergeTrees(t1->right, t2->right);
            cout<<t->val<<endl;
        }
        return t;
    }
};


//初始化二叉树
TreeNode* initTree(int elements[], int size){
    if(size<1){
        return NULL;
    }
    TreeNode **treeNode = new TreeNode* [size];
    for(int i=0; i<size; i++){
        if(elements[i] == 0)
            treeNode[i] = NULL;
        else
            treeNode[i] = new TreeNode(elements[i]);
    }
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(treeNode[0]);

    TreeNode* node;
    int index = 1;
    while(index < size){
        node = nodeQueue.front();
        nodeQueue.pop();
        nodeQueue.push(treeNode[index++]);
        node->left = nodeQueue.back();
        nodeQueue.push(treeNode[index++]);
        node->right = nodeQueue.back();
    }
    return treeNode[0];
}


//test
int main(){
    Solution slo;
    int t01[] = { 1, 2, 3, 4, 5, 0, 6, 0, 7, 0, 8 };
    int t02[] = { 2, 4, 1, 4, 0, 1, 6 };
    TreeNode *t1 = initTree(t01, 11);
    TreeNode *t2 = initTree(t02, 7);

    slo.mergeTrees(t1, t2);

    return 0;
}




