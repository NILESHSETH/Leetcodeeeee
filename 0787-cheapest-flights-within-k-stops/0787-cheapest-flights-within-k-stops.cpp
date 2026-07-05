class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& nums, int src, int dst,
                          int k) {

        vector<pair<int, int>> adj[n];
        for (int i = 0; i < nums.size(); i++) {
            int u = nums[i][0];
            int v = nums[i][1];
            int wt = nums[i][2];

            adj[u].push_back({v, wt});
        }

        vector<int> dist(n, 1e9);
        queue<pair<int, pair<int, int>>> q;

        dist[src] = 0;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            int stop = q.front().first;
            int node = q.front().second.first;
            int dis = q.front().second.second;
            q.pop();

            // CHANGED: Do not return here.
            // Just skip processing if stops exceed k.
            if (stop > k)
                continue;

            for (auto it : adj[node]) {
                int adjnode = it.first;
                int wt = it.second;
                int newdist = wt + dis;

                // REMOVED:
                // if(stop == k) return dist[dst];

                if (newdist < dist[adjnode]) {
                    dist[adjnode] = newdist;
                    q.push({stop + 1, {adjnode, newdist}});
                }
            }
        }

        if (dist[dst] == 1e9)
            return -1;

        return dist[dst];
    }
};