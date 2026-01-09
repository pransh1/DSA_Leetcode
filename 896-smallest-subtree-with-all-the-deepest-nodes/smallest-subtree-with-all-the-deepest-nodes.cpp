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
    int maxDepth = 0;

    // Step 1: find maximum depth
    int findDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(findDepth(root->left), findDepth(root->right));
    }

    // Step 2: LCA-style recursion
    TreeNode* dfs(TreeNode* root, int depth) {
        if (!root) return nullptr;

        // If this node is at deepest level
        if (depth == maxDepth) {
            return root;
        }

        TreeNode* left = dfs(root->left, depth + 1);
        TreeNode* right = dfs(root->right, depth + 1);

        // If deepest nodes are found in both subtrees
        if (left && right) {
            return root;   // this is the LCA
        }

        // Else propagate non-null child upward
        return left ? left : right;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        maxDepth = findDepth(root);
        return dfs(root, 1);
    }
};
