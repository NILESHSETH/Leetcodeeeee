

class Solution {
public:

    void markparent(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parent) {

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* current = q.front();
            q.pop();

            if (current->left) {

                // CHANGE 1:
                // parent(current->left) = current;
                // unordered_map is accessed using []
                parent[current->left] = current;

                q.push(current->left);
            }

            if (current->right) {

                // CHANGE 2:
                parent[current->right] = current;

                q.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> parent;

        markparent(root, parent);

        // CHANGE 3:
        // map<TreeNode*, bool> c = vis;
        // vis wasn't declared.
        unordered_map<TreeNode*, bool> vis;

        queue<TreeNode*> q;

        q.push(target);

        // CHANGE 4:
        // Target should be marked visited.
        vis[target] = true;

        int level = 0;

        while (!q.empty()) {

            if (level++ == k)
                break;

            // CHANGE 5:
            // int size() = q.size();
            int size = q.size();

            for (int i = 0; i < size; i++) {

                // CHANGE 6:
                // TreenNode -> TreeNode
                TreeNode* currnode = q.front();

                q.pop();

                if (currnode->left && !vis[currnode->left]) {

                    q.push(currnode->left);

                    vis[currnode->left] = true;
                }

                if (currnode->right && !vis[currnode->right]) {

                    q.push(currnode->right);

                    // CHANGE 7:
                    // Removed stray 'v'

                    // CHANGE 8:
                    // You wrote vis[currnode->left]
                    vis[currnode->right] = true;
                }

                // CHANGE 9:
                // current doesn't exist here.
                // Use currnode.
                if (parent[currnode] && !vis[parent[currnode]]) {

                    q.push(parent[currnode]);

                    // CHANGE 10:
                    // Missing = true
                    vis[parent[currnode]] = true;
                }
            }
        }

        vector<int> ans;

        while (!q.empty()) {

            TreeNode* current = q.front();

            q.pop();

            // CHANGE 11:
            // puah_back(current)
            // Need node value.
            ans.push_back(current->val);
        }

        return ans;
    }
};