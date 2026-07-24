class Solution {
public:
    int lowerbound(vector<int>& nums, int n, int x) {
        int lo = 0;
        int hi = n - 1;
        int ans = n;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] >= x) {
                ans = mid;
                hi = mid - 1;
            } else
                lo = mid + 1;
        }
        return ans;
        ;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        int cnt_max = 0;
        int idx = 0;
        // int idx = lower_bound(nums[i].begin(), nums[i].end(), 1) -nums[i].begin();

        for (int i = 0; i < n; i++) {
            sort(nums[i].begin(), nums[i].end());
            int firstOne = lowerbound(nums[i], m, 1);
            int cnt_ones = m - firstOne;
        
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                idx = i;
            }
        }

        return {idx, cnt_max};
    }
};