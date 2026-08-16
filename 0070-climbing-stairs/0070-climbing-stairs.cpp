class Solution {
public:
    int helper(int n, vector<int>&dp) {
        if(n == 0 || n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        return  dp[n] = helper(n-1,dp) + helper(n-2,dp);
    }

    int climbStairs(int n) {
        if(n==1) return 1;
        vector<int>dp(n+1,-1);
        helper(n,dp);
        return dp[n];
    }
};