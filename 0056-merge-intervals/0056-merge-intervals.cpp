// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         int i = 0; 
//         int j = i+1;
//         vector<vector<int>>ans;
//         while(i < n){
//             int l = nums[i][1];
//             int s = nums[j][0];
//             while(j < n && l >= s){
//                 j++;
//                 if(j < n) s = nums[j][0];
//             }
//             vector<int>v = {nums[i][0],l}; 
//             i = j;
//             j++;
//             ans.push_back(v);  
//         }
//         return ans;
        
//     }
// };



// // class Solution {
// // public:
   
// //     vector<vector<int>> merge(vector<vector<int>>& nums) {
// //         int n = nums.size();
// //          sort(nums.begin(), nums.end(), [](const vector<int>& a, const vector<int>& b) {
// //         return a[1] < b[1];
// //         });
// //         vector<vector<int>>ans;
// //         for(int i = 0; i < n-1;i++){
// //             int l = nums[i][1];
// //             int f = nums[i+1][0];
// //             if(l <= r){
// //                 ans.push_back({nums[i][0], nums[i+1][]})
// //             }
// //         }
// //     }
// // };


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = i + 1;
        vector<vector<int>> ans;

        while(j < n){
            int l = nums[i][1];
            int s = nums[j][0];

            while(j < n && l >= s){// s humlog is liye le rahe hai kyuki..like humlog pahle hi check kar le rhe hi ki jo humlog vector ke khade hai..uska starting pichle wale ke ending se bada  hai
                l = max(l, nums[j][1]); // CHANGE 1: keep the maximum ending point
                j++;
                if(j < n) s = nums[j][0];// ye uske next wale ka starting point hai
            }

            vector<int>v = {nums[i][0], l}; // CHANGE 2: use l instead of nums[j-1][1]
            ans.push_back(v);

            i = j;
            j++;
        }

        if(i < n){ // CHANGE 3: add the last interval if it was not processed
            ans.push_back(nums[i]);
        }

        return ans;
    }
};