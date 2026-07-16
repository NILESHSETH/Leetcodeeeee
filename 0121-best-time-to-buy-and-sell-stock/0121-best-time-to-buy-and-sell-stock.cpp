class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[n-1];
        int profit = 0;
        for(int i = n-2; i >= 0;i--){
            if(nums[i] < maxi){
                profit = max(profit,maxi - nums[i]);
            }
            else maxi = nums[i];
        }
        return profit;
        
      
    }
};