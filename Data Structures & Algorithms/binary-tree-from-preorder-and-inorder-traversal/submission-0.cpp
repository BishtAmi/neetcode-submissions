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
    TreeNode* solve(int i, int j, int l, int r, vector<int>& preorder, map<int, int>& index) {
        if (i > j) return nullptr;
        int idx = index[preorder[i]];
        int len = idx - l;
        TreeNode* root = new TreeNode(preorder[i]);
        root->left = solve(i + 1, i + len, l, idx - 1, preorder, index);
        root->right = solve(i + len + 1, j, idx + 1, r,preorder, index);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return solve(0, n - 1, 0, n - 1, preorder, index);
    }
};
