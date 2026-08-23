class Solution {
public:

    int helper(int i, int j , vector<int>&nums, vector<vector<int>>&dp){
        if(i > j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];
        int takei = nums[i] + min(helper(i+2,j,nums,dp), helper(i+1,j-1, nums,dp));
        int takej = nums[j] + min(helper(i+1,j-1,nums,dp), helper(i,j-2,nums,dp));
        return dp[i][j] = max(takei,takej);

    }
    bool stoneGame(vector<int>& nums) {
        int n = nums.size();
        int long long sum = 0;
        for(auto it: nums) sum += it;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int alisesum = helper(0,n-1,nums,dp);
        if(sum/2 <= alisesum) return true;
        else return false;
        
    }
};