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
    vector<vector<int>> zigzagLevelOrder(TreeNode* node) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(node == NULL) return ans;
        q.push(node);
        bool l2r = true;
        while(!q.empty()){
            int size = q.size();
            vector<int>level(size);
            for(int i = 0; i < size;i++){
                TreeNode* currnode = q.front();
                q.pop();
                int index = l2r?i:size-i-1;
                level[index] = currnode->val;
                if(currnode->left) q.push(currnode->left);
                if(currnode->right) q.push(currnode->right);

            }
            if(l2r) l2r = false;
            else l2r = true;
            ans.push_back(level);
        }
        return ans;
    }
};