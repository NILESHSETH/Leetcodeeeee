class Solution {
public:
    // meathod to find the start
    void findstart(TreeNode* root, int start, TreeNode* &temp) {
        if (root == NULL)
            return;
        if (root->val == start) {
            temp = root;
            return;
        }
        findstart(root->left, start, temp);
        findstart(root->right, start, temp);
    }

    // meathod to find the bidirectional binery tree
    void markparent(TreeNode* node,unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(node);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (current ->left) {
                parent[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent[current->right] = current;
                q.push(current->right);
            }
        }
    }
    // helper finction funstion to find the time
    // void helper(TreeNode* node, TreeNode*start, int time,
    // unordered_map<TreeNode*,TreeNode*>&parent) {

    // }

    int amountOfTime(TreeNode* root, int start) {
        if (root == NULL)return 0;
        unordered_map<TreeNode*, TreeNode*> parent;
        markparent(root, parent);
        // here the value of the start is given we need to find the pointer to
        // the start so that we can tarverse easily
        TreeNode* temp = root;
        findstart(root, start, temp);
        // last fcunction
        int time = 0;
        // helper(root, temp, time, parent);

        unordered_map<TreeNode * , bool> vis;
        queue<TreeNode*> q;
        q.push(temp);
        vis[temp] = true;
        while (!q.empty()) {
            int size = q.size();
            bool burned = false;
            for (int i = 0; i < size; i++) {
                TreeNode* currnode = q.front();
                q.pop();
                if (currnode->left && !vis[currnode->left]) {
                    q.push(currnode->left);
                    vis[currnode->left] = true;
                    burned = true;
                }
                if (currnode->right && !vis[currnode->right]) {
                    q.push(currnode->right);
                    vis[currnode->right] = true;
                    burned = true;

                }
                if (parent[currnode] && !vis[parent[currnode]]) {
                    q.push(parent[currnode]);
                    vis[parent[currnode]] = true;
                    burned = true;

                }
            }
            if(burned) time++;
        }
        return time;
    }
};
