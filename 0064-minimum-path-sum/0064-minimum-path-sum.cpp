class Solution {
public:
    int helper(int row, int col , vector<vector<int>>&nums,long long &sum,vector<vector<int>>&dp){
        if(row < 0 || col < 0) return INT_MAX;
        if(row == 0 && col == 0) return dp[0][0] = nums[0][0];
        if(dp[row][col] != -1) return dp[row][col];
        int up = helper(row -1, col, nums, sum,dp);
        int left =  helper(row , col -1, nums,sum,dp);
        return dp[row][col] =nums[row][col] + min(up,left);

    }
    int minPathSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        long long sum = nums[n-1][m-1];
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,nums,sum,dp);
        
    }
};