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


    int helper(TreeNode* node, int &cnt ){
        if(node == NULL) return 0;

        int lheight = helper(node->left,cnt);
        int rheight = helper(node->right,cnt);
        cnt = max(cnt, lheight + rheight);
        return 1 + max(lheight,rheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int cnt = 0;
        helper(root, cnt);
        return cnt;
    }
};



// // /**
// //  * Definition for a binary tree node.
// //  * struct TreeNode {
// //  *     int val;
// //  *     TreeNode *left;
// //  *     TreeNode *right;
// //  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// //  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// //  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// //  * };
// //  */
// // class Solution {
// // public:
// //     int sum(TreeNode* node, int &maxi){
// //         if(node == NULL) return 0;
// //         int l =  sum(node->left,maxi);
// //         int r =  sum(node->right,maxi);
// //         maxi = max(maxi, l+r);
// //         return 1+ max(l,r);
// //     }
// //     int diameterOfBinaryTree(TreeNode* root) {
// //         int maxi = 0;
// //         maxi = sum(root, maxi);
// //         return maxi;
        
// //     }
// // };
// class Solution {
// public:
//     int height(TreeNode* node, int &maxi) {
//         if (node == NULL)
//             return 0;

//         int l = height(node->left, maxi);
//         int r = height(node->right, maxi);

//         maxi = max(maxi, l + r);

//         return 1 + max(l, r);
//     }

//     int diameterOfBinaryTree(TreeNode* root) {
//         int maxi = 0;
//         height(root, maxi);
//         return maxi;
//     }
// };
















