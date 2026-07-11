// class Solution {
// public:
//     bool dfs(int node, int par, vector<vector<int>>& adj, vector<int>& vis) {
//         vis[node] = 1;

//         for (int it : adj[node]) {
//             if (!vis[it]) {
//                 if (dfs(it, node, adj, vis))
//                     return true;
//             } else if (it != par) {
//                 return true;
//             }
//         }

//         return false;
//     }

//     bool hasCycle(int n, vector<vector<int>>& adj) {
//         vector<int> vis(n, 0);

//         for (int i = 0; i < n; i++) {
//             if (!vis[i]) {
//                 if (dfs(i, -1, adj, vis))
//                     return true;
//             }
//         }

//         return false;
//     }
//     int countCompleteComponents(int n, vector<vector<int>>& edges) {
//         int m = edges[0].size();
//         vector<vector<int>>adj(n,vector<int>(m,-1));
//         for(int i = 0; i <n;i++){
//             adj[edges[i][0]].push_back(edges[i][1]);
//             adj[edges[i][1]].push_back(edges[i][0]);
//         }
//         int cnt = 0;
//         for(int i = 0; i<n;i++){
//             if(hasCycle(i, adj)) cnt++;
//         }
//         return cnt;

//     }
// };
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            queue<int> q;
            q.push(i);
            vis[i] = true;

            int nodes = 0;
            int edgeCount = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                nodes++;
                edgeCount += adj[u].size();

                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }

            edgeCount /= 2;

            if (edgeCount == nodes * (nodes - 1) / 2)
                ans++;
        }

        return ans;
    }
};