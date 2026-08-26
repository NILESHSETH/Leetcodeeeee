class Solution {
public:
    int helper(int ind, int target, vector<int>&nums, vector<vector<int>>&dp){
        // if(target == 0) return  dp[ind][target] = 1;
        // if(ind == 0) return  dp[ind][target] = target == nums[0];
        // if(target == 0) return 1;
        if(ind == 0){
            if(target%nums[ind] == 0) return target/nums[ind];
            else return 1e9;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int nottake = helper(ind-1, target, nums, dp);
        int take = 1e9;
        if(target >= nums[ind]) take = 1 + helper(ind,target - nums[ind], nums, dp);
        return dp[ind][target] = min(take, nottake);
        
    }
    int coinChange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(target + 1, -1));
        int ans =  helper(n-1,target, nums, dp);
        return ans == 1e9?-1:ans ;
    }
};