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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;

        return helper(root, false);
    }

    int helper(TreeNode* root, bool left) {
        if(!root) return 0;

        if(left && root->left == NULL && root->right == NULL) return root->val;

        return helper(root->left, true) + helper(root->right, false);
    }
};