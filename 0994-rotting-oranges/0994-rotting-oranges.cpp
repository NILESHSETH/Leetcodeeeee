class Solution {
public:
    int orangesRotting(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        int cnt = 0;
        int cntf = 0;
        int delr[4] = {-1,0,1,0};
        int delc[4] = {0,-1,0,1};
        int time = 0;
        vector<vector<int>>vis(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0; i < n;i++){
            for(int j = 0;j <m;j++){
                if(nums[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 1;
                    if(nums[i][j] == 1) cntf++;
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first.first;
            int t = q.front().second;
            int c = q.front().first.second;
            time = max(time,t);
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + delr[i];
                int nc = c + delc[i];
                if(nr >= 0 && nc >= 0 && nr< n&& nc < m && nums[nr][nc] == 1 && vis[nr][nc] != 2){
                    q.push({{nr,nc}, t+1});
                    vis[nr][nc] = 2;
                    cnt++;
                }
            }
        }
        if(cnt == cntf ) return time;
        else return -1;
        
    }
};