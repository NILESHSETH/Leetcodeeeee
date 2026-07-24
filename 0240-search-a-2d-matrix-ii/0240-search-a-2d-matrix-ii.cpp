class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n = nums.size();
        int m = nums[0].size();
        int row = 0;
        int col = m-1;
        while(row <n  && col >= 0 ){
            if(nums[row][col] == target) return true;
            else if(nums[row][col] < target) row++;
            else col --;
        }
        return false;
    }
};
// cannot apply typical binary search -> we need to think of elimination 

// class Solution {
// public:
//   bool bs(vector<int>&nums, int n, int m,int target){
//         int lo =0;
//         int hi = m-1;
//         while(lo <= hi){
//             int mid = lo + (hi- lo)/2;
//             if(nums[mid] == target) return true;
//             else if(nums[mid] < target) lo = mid +1;
//             else hi = mid -1;
//         }
//         return false;
//     }
//     bool searchMatrix(vector<vector<int>>& nums, int target) {
//         int n = nums.size();
//         int m = nums[0].size();
        

//         int lo = 0;
//         int hi =n-1;
//         bool flag = false;
//         while(lo <= hi){
//             int mid = lo + (hi-lo)/2;
//             if(nums[mid][0] <= target){
//                 lo = mid +1;
//                 flag = bs(nums[mid],n,m,target);// returning too quickly without checking the upcomming events

//             }
//             else if (nums[mid][0] > target) hi = mid -1;
//         }
//         return flag;
//     }
// };