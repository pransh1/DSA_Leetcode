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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ans;
        sumOfNode(root, 0, targetSum, ans);
        return res;
    }

    void sumOfNode(TreeNode* root, int sum, int target, vector<int>& group) {
        if(root == NULL) return;
        sum += root->val;
        group.push_back(root->val);
        if(sum == target && root->left == NULL && root->right == NULL) res.push_back(group);

        if(root->left != NULL) {
            sumOfNode(root->left, sum, target, group);
        }
        if(root->right != NULL) {
            sumOfNode(root->right, sum, target, group);
        }
        group.pop_back();
    }
};