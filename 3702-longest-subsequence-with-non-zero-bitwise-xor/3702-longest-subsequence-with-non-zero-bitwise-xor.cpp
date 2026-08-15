// class Solution {
// public:

//     // helper() returns the maximum length of a subsequence
//     // starting from index 'ind' with current XOR = 'xr'
//     int helper(int ind, vector<int>& nums, int xr,
//                vector<unordered_map<int, int>>& dp) {

//         // If we have processed every element
//         if(ind == nums.size()) {

//             // If final XOR is non-zero, this is a valid subsequence.
//             // Its length is calculated by the recursive calls.
//             if(xr != 0)
//                 return 0;

//             // If final XOR is 0, we don't want this subsequence.
//             // We return a very small value so that max() will never choose it.
//             return -1000000;
//         }


//         // dp[ind] is a map.
//         // dp[ind][xr] stores the answer for this particular:
//         //
//         //       index = ind
//         //       XOR   = xr
//         //
//         // If we have already solved this state, don't calculate it again.
//         if(dp[ind].count(xr))
//             return dp[ind][xr];


//         // FIRST: Don't take nums[ind].
//         //
//         // We move to the next index.
//         // XOR does not change because we didn't take the element.
//         int nottake = helper(ind + 1, nums, xr, dp);


//         // SECOND: Take nums[ind].
//         //
//         // Because we took one element, add 1 to the answer.
//         //
//         // XOR becomes:
//         //
//         //       old XOR ^ current element
//         //
//         // Then move to the next index.
//         int take = 1 + helper(ind + 1,
//                               nums,
//                               xr ^ nums[ind],
//                               dp);


//         // We have two choices:
//         //
//         // 1. nottake -> don't select nums[ind]
//         // 2. take    -> select nums[ind]
//         //
//         // We want the longer valid subsequence.
//         return dp[ind][xr] = max(take, nottake);
//     }


//     int longestSubsequence(vector<int>& nums) {

//         // Number of elements in the array.
//         int n = nums.size();


//         // dp is a vector of maps.
//         //
//         // dp[ind] contains all XOR states that we actually visit
//         // for that particular index.
//         //
//         // This is used instead of:
//         //
//         // vector<vector<int>> dp(n, vector<int>(maxXor + 1, -1));
//         //
//         // because maxXor can be very large and that can cause
//         // Memory Limit Exceeded.
//         vector<unordered_map<int, int>> dp(n);


//         // Start from:
//         //
//         // ind = 0  -> first element
//         // xr  = 0  -> initially XOR is 0
//         //
//         // The helper will try both:
//         //
//         //       NOT TAKE
//         //       TAKE
//         //
//         // for every element.
//         return helper(0, nums, 0, dp);
//     }
// // };
// class Solution {
//     int solve(vector<int>& nums , int idx , int ans , int XOR, vector <int>&DP)
//     {
//         if (idx >= nums.size()) return ans;
//         if (DP[idx]!=  -1) return DP[idx];
//         int take = INT_MIN;
//         if (XOR ^ nums[idx]) take = solve(nums , idx + 1 , ans + 1 , XOR ^ nums[idx] , DP);
//         int ignore = solve(nums , idx + 1 , ans , XOR , DP);

//         return DP[idx] = max(take , ignore);
//     }
// public:
//     int longestSubsequence(vector<int>& nums) {
//         int XOR = 0;
//         bool same = true;
//         int c = nums[0];
//         for (auto i : nums)
//         {
//             XOR ^= i;
//             if (same && i != c)
//             {
//                 same = false;
//             }
//         }
//         if (XOR) return nums.size();
//         if (same && nums.size() % 2 == 0)
//         {
//             if (c == 0) return 0;
//             return nums.size() - 1;
//         } 
//         vector <int> DP(nums.size() , -1);
//         return solve(nums , 0 , 0 , 0 , DP);
//     }
// };
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xr=0;
        int f=0;
        for(auto & it:nums){
            xr^=it;
            if(it!=0){
                f=1;
            }
        }
        if(xr==0){
            if(f==0){
                return 0;
            }
            else{
                return n-1;
            }
        }
        else{
            return n;
        }
        return 0;
    }
};