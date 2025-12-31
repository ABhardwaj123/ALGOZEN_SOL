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

//inorder traversal of a binary tree
//time complexity : O(N)
//space complexity : O(N) 

void traversal(TreeNode* root , vector<int>& answer){
        if(root == NULL) return;

        traversal(root->left , answer);
        answer.push_back(root->val);
        traversal(root->right , answer);
    }

vector<int> inorderTraversal(TreeNode* root) {

    vector<int> answer;

    traversal(root , answer);

    return answer;

}

