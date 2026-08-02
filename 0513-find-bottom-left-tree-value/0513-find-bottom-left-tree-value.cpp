/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* node, vector<int>& ans, int level) {
        if (node == NULL)
            return;
        if (ans.size() == level)
            ans.push_back(node->val);
        helper(node->left, ans, level + 1);

        helper(node->right, ans, level + 1);
    }
    int findBottomLeftValue(TreeNode* root) {
     vector<int>ans;

        if(root == NULL) return NULL;
        helper(root, ans,0);
        return ans[ans.size() -1];
    }
};
