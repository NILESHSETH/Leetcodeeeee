// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int n = nums.size();
//         int lo= 0;
//         int hi = n-1;
//         while(lo <= hi){
//             int mid = lo + (hi-lo)/2;
//             if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;

//             if(nums[mid] == nums[lo]) {
//                 lo++;
//                 continue;
//             }

//             if(nums[mid] == nums[hi]){
//                  hi--;
//                 continue;
//             }

//             if(nums[mid] > nums[lo]){
//                 hi = mid-1;
//             }
//             else {
//                 lo = mid+1;
//             }
//         }
//         return -1;
//     }
// };
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] < nums[mid + 1])
                lo = mid + 1;
            else
                hi = mid;
        }

        return lo;
    }
};