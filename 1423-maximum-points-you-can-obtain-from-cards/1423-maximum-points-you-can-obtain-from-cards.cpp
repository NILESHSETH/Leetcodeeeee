class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        long long maxi = INT_MIN;
        for(int i = 0; i <= k-1; i++){
            sum += nums[i];
        }
        maxi = max(sum , maxi);
        int r = k-1;
        int l = n;
        while(r>= 0){
            sum -= nums[r];
            r--;
            l--;
            sum+= nums[l];
           maxi = max(sum, maxi);
        }
        return maxi;
    }
};