#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//doing level order traversal in a binary tree
//time complexity : O(N)
//space complexity : O(N)

vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> answer;
            int size = q.size();

            for(int i = 1 ; i <= size ; i++){
                TreeNode* front = q.front();
                q.pop();

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);

                answer.push_back(front->val);
            }

            result.push_back(answer);
        }

        return result;
    }
