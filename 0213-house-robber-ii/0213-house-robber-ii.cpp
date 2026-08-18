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
    int rob1(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return helper(n-1,nums,dp);

    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        vector<int>temp2;
        if(n==1) return nums[0];
        for(int i = 0; i < n;i++){
            if(i!= 0) temp.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        return max(rob1(temp), rob1(temp2));
    }
};