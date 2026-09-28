class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& nums) {
        int n = nums.size();
        long long cnt = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            int lo = i + 1;
            int hi = n - 1;
            long long res = i;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (nums[mid][0] <= nums[i][1]) {
                    res = mid;
                    lo = mid + 1;
                } else
                    hi = mid - 1;
            }
            cnt += res - i;
        }
        return cnt;
    }
};