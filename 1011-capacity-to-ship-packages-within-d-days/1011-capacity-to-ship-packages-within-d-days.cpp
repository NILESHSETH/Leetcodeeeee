class Solution {
public:
    int possible(vector<int>& nums, int capacity) {

        int days = 1;
        int load = 0;

        for (int weight : nums) {

            if (load + weight > capacity) {
                days++;
                load = weight;
            } else {
                load += weight;
            }
        }

        return days;
    }
    int shipWithinDays(vector<int>& nums, int day) {
        int n = nums.size();
        
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (possible(nums, mid) <= day) {
                ans = mid;
                hi = mid - 1;
            } else
                lo = mid + 1;
        }
        return ans;
    }
};