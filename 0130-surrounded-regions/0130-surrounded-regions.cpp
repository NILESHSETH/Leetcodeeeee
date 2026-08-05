class Solution {
public:
    void solve(vector<vector<char>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                if(i == n-1 | i == 0 | j == m-1 | j == 0){
                    if(nums[i][j] == 'O'){
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
        }
        int delr[4] = {-1,0,1,0};
        int delc[4] = {0,-1,0,1};
      
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4;i++){
                int nr = r + delr[i];
                int nc = c + delc[i];
                if(nr >= 0 && nc >= 0 && nr < n&& nc < m && nums[nr][nc] == 'O' && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                if(nums[i][j] == 'O' && vis[i][j] == 0) nums[i][j] = 'X';
            }
        }
        
    }
};