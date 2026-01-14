#include<iostream>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  //inverting a binary tree
  //TC : O(N) {visiting each and every node}
  //SC : O(N) {the new tree we return (for the answer)}

void invert(TreeNode* root , TreeNode*& temp){
        if(root == NULL) return;

        if(root->left){
            TreeNode* newNode = new TreeNode(root->left->val);
            temp->right = newNode;
        }

        if(root->right){
            TreeNode* newNode = new TreeNode(root->right->val);
            temp->left = newNode;
        }

        invert(root->left , temp->right);
        invert(root->right , temp->left);

    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;

        TreeNode* newTree = new TreeNode(root->val);
        TreeNode* temp = newTree;
        invert(root , temp);

        return newTree;
    }