#include<iostream>
#include<stdlib.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//deleting a node in a BST
//time complexity : O(H) {H is height of the BST}
//space comeplexity : O(1)

TreeNode* deleteInBST(TreeNode* root , int key){
        if(root == NULL) return NULL;
        if(root->val == key) return helper(root);

        TreeNode* temp = root;

        while(temp != NULL){
            if(temp->val > key){//we move left
                if(temp->left && temp->left->val == key){
                    temp->left = helper(temp->left);
                    break;
                }else{
                    temp = temp->left;
                }
            }else{
                if(temp->right && temp->right->val == key){
                    temp->right = helper(temp->right);
                    break;
                }else{
                    temp = temp->right;
                }
            }
        }
        return root;
    }

    TreeNode* helper(TreeNode* node){
        if(node==NULL) return NULL;
        if(node->left==NULL) return node->right;
        if(node->right==NULL) return node->left;

        TreeNode* detach = node->right;
        TreeNode* finalNode = node->left;
        TreeNode* temp = finalNode;

        while(temp->right != NULL){
            temp = temp->right;
        }

        temp->right = detach;
        return finalNode;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        return deleteInBST(root , key);
    }