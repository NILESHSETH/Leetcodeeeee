class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
		int hi = n - 1;
		int lo = 0;
		int ans = INT_MAX;
		int ind = 0;
		while (lo <= hi) {
			int mid = (lo + hi)/2;
			// search space is already sorted
			// them always arr[lo] is smaller
			// in that search space
			
			if (nums[lo] <= nums[hi]) {
				if (ans >= nums[lo]) {
					ans = nums[lo];
					break;
				}
			}
			if (nums[lo] <= nums[mid]) {
				if (ans > nums[lo]) {
					ans = nums[lo];
				}
				lo = mid + 1;
				
			}
			
			else {
				if (ans > nums[mid]) {
					ans = nums[mid];
				}
				hi = mid - 1;
				
			}
		}
		return ans;
        
    }
};