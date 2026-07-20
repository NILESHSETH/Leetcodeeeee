class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int m = -1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            m = mid;
            if (nums[mid] >= target)
                j = mid - 1;
            else
                i = mid + 1;
        }
        int lo = i;
        if (lo == n || nums[lo] != target)
            lo = -1;
        i = 0;
        j = n - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] > target)
                j = mid - 1;
            else
                i = mid + 1;
        }
        int l = i - 1;
        if (l < 0 || nums[l] != target)
            l = -1;
        return {lo, l};
    }
};