#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//BST Iterator : inorder traversal of BST using stack
//time complexity : O(1) on average 
//explanation of time complexity : N(total number of nodes) / N (total next calls) = O(1) 
//space complexity : O(H) {H = height of tree}


class BSTIterator {
public:
    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {
        TreeNode* temp = root;

        while(temp != NULL){
            st.push(temp);
            temp = temp->left;
        }
    }
    
    int next() {
        int val = st.top()->val;
        TreeNode* node = st.top();
        st.pop();

        if(node->right){
            TreeNode* temp = node->right;

            while(temp != NULL){
                st.push(temp);
                temp=temp->left;
            }
        } 

        return val;
    }
    
    bool hasNext() {
        if(st.empty()) return false;
        return true;
    }
};