class Solution {
public:
    void helper(TreeNode* node, vector<int>&ans,int level){
        if(node == NULL) return;
        if(ans.size() == level) ans.push_back(node->val);
        helper(node->right, ans, level+1);
        helper(node->left, ans, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
                vector<int>ans;

        if(root == NULL) return ans;
        helper(root, ans,0);
        return ans;
    }
};