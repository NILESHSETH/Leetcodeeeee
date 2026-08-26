class Solution {
public:
    int helper(int ind,int target, vector<int>&nums, vector<vector<int>>&dp){
        if(ind == 0){
            if(nums[ind] == 0 && target == 0) return 2;
            if(nums[ind] == target || target == 0) return 1;
            else return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int nottake = helper(ind -1, target, nums, dp);
        int take = 0;
        if(target >= nums[ind]) take = helper(ind -1, target - nums[ind], nums, dp);
        return dp[ind][target] = take + nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto i : nums) sum += i;
        if((target+ sum)%2 != 0 || (sum + target) < 0) return 0;

        vector<vector<int>>dp(n, vector<int>(sum + target + 1,-1));
        return helper(n-1, (sum + target)/2 , nums, dp);
        
    }
};