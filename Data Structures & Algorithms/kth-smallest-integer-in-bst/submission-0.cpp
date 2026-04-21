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
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return -1;
        int left = kthSmallest(root->left,k);
        cnt++;
        if(cnt == k) return root->val;
        int right = kthSmallest(root->right,k);
        if(left == -1)
          return right;
        return left;
    }
};
