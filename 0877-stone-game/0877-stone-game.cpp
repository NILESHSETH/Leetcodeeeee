class Solution {
public:
    int helper(int i , int j , vector<int>&nums,vector<vector<int>>&dp){
        int n = nums.size();
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];
        long long takei = nums[i] + min(helper(i+2,j,nums,dp), helper(i+1,j-1,nums,dp));
        long long takej = nums[j] + min(helper(i,j-2,nums,dp), helper(i+1, j-1,nums,dp));
        return dp[i][j] =  max(takei,takej);
    }
    bool stoneGame(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i = 0; i< n;i++) sum += nums[i];
        vector<vector<int>>dp(n,vector<int>(n,-1));

        long long sumi = helper(0,n-1,nums,dp);
        if(sumi >= sum/2) return true;
        else return false;
    }
};