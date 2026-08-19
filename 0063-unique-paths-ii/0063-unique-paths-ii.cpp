class Solution {
public:
    int helper(int row, int col, vector<vector<int>>&nums, vector<vector<int>>&dp){
        if(row < 0 || col < 0) return 0;
        if(nums[row][col] == 1) return dp[row][col] = 0;
        if(row == 0 && col == 0) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        int up = helper(row-1, col , nums, dp);
        int left = helper(row, col-1, nums, dp);
        return dp[row][col] = up + left;
    }


    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(n-1, m-1,nums, dp);


    }
};