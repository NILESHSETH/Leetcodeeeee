class Solution {
public:
//  int lowerbound(vector<int>& nums, int n, int x) {
//         int lo = 0;
//         int hi = n - 1;
//         int ans = n;
//         while (lo <= hi) {
//             int mid = (lo + hi) / 2;
//             if (nums[mid] >= x) {
//                 ans = mid;
//                 hi = mid - 1;
//             } else
//                 lo = mid + 1;
//         }
//         return ans;
        
//     }
    bool bs(vector<int>&nums, int n, int m,int target){
        int lo =0;
        int hi = m-1;
        while(lo <= hi){
            int mid = lo + (hi- lo)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] < target) lo = mid +1;
            else hi = mid -1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n = nums.size();
        int m = nums[0].size();
        

        int lo = 0;
        int hi =n-1;
        bool flag = false;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid][0] <= target){
                lo = mid +1;
                flag = bs(nums[mid],n,m,target);

            }
            else if (nums[mid][0] > target) hi = mid -1;
        }
        return flag;
    }
};