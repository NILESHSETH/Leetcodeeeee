class Solution {
public:
    void dfs(int node, vector<int>adj[], vector<int>&vis){
        vis[node] = 1;
        for(auto adjnode : adj[node]){
            if(!vis[adjnode]){
                dfs(adjnode, adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(int i = 0; i< n;i++){
            for(int j = 0;  j< m;j++){
                if(nums[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;

    }
};