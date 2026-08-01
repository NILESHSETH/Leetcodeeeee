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

    int helper(TreeNode* node , int &sum){
        if(node == NULL) return 0;
        int left = max(0,helper(node->left,sum));
        int right = max(0,helper(node->right,sum));

        sum = max(sum , node->val + left + right);

        return node->val +max(left,right) ;
    }
    int maxPathSum(TreeNode* node) {
        if(node == NULL) return 0;
        int sum = INT_MIN;
        helper(node , sum);
        return sum;
        
    }
};


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
//  */
// class Solution {
// public:
//     int helper(TreeNode* node, int &sum){
//         if(node == NULL) return 0;
//         int l =max(0,helper(node->left,sum)); 
//         int r= max(0,helper(node->right,sum)); 
//         sum = max(sum, node-> val + l + r);
//         return max(l,r) + node->val;
//     }
//     int maxPathSum(TreeNode* root) {
//         int sum = INT_MIN;
//         helper(root, sum);
//         return sum;
//     }
// };