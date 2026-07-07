class Solution {
public:
    int func(vector<int>& nums, int g) {
        if (g < 0) return 0;

        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int cnt = 0;

        while (j < n) {
            sum += nums[j]%2;

            while (sum > g) {
                sum -= nums[i]%2;
                i++;
            }

            cnt += (j - i + 1); 
            j++;
        }

        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums,k) - func(nums,k-1);
    }
};