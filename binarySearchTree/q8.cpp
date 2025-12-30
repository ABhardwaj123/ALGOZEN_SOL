#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//inserting a node in a BST
//time complexity : O(H) {H is height of the BST}
//space comeplexity : O(1)

TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* tree = new TreeNode(val);
            return tree;
        }
        
        TreeNode* temp = root;

        while(temp != NULL){
            if(temp->val < val){//we have to move right
                if(temp->right == NULL){
                    TreeNode* newNode = new TreeNode(val);
                    temp->right = newNode;
                    break;
                }else{
                    temp = temp->right;
                }
            }else{
                if(temp->left == NULL){
                    TreeNode* newNode = new TreeNode(val);
                    temp->left = newNode;
                    break;
                }else{
                    temp=temp->left;
                }
            }
        }

        return root;
    }

