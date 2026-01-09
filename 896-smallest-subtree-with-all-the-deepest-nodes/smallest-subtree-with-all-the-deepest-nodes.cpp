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
    // Returns:
    // 1) maximum depth below this node
    // 2) smallest subtree containing all deepest nodes
    pair<int, TreeNode*> dfs(TreeNode* root) {
        // Base case
        if (!root) {
            return {0, nullptr};
        }

        // Recurse on children
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // If left subtree is deeper
        if (left.first > right.first) {
            return {left.first + 1, left.second};
        }

        // If right subtree is deeper
        if (right.first > left.first) {
            return {right.first + 1, right.second};
        }

        // Equal depth → this node is LCA of deepest nodes
        return {left.first + 1, root};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
