class Solution {
public:
    int helper(int i , int j , vector<int>&nums){
        int n = nums.size();
        if(i>j) return 0;
        if(i==j) return nums[i];
        long long takei = nums[i] + min(helper(i+2,j,nums), helper(i+1,j-1,nums));
        long long takej = nums[j] + min(helper(i,j-2,nums), helper(i+1, j-1,nums));
        return max(takei,takej);
    }
    bool predictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        long long sum = 0;
        for(int i = 0; i< n;i++) sum += nums[i];
        long long sumi = helper(0,n-1,nums);
        if(sumi >= sum-sumi) return true;
        else return false;
    }
};