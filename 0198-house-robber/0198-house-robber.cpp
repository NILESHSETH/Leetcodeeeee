class Solution {
public:
    
    int helper(int i,vector<int>&nums,vector<int>&dp){
        if(i==0) return nums[0];
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i];
        if(i > 1) take += helper(i-2,nums,dp);
        int nottake = helper(i-1,nums,dp);
        return dp[i]= max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return helper(n-1,nums,dp);

    }
};