/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int cnt = 0;
    void solve(TreeNode *root,int maxi)
    {
        if(root == nullptr)
           return;

        if(root->val >= maxi)
           cnt++;   
        solve(root->left,max(maxi,root->val));
        solve(root->right,max(maxi,root->val));      
    }
    int goodNodes(TreeNode* root) {
        solve(root,-101);
        return cnt;
    }
};
