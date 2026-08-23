class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i = 0; i < n - 2; i++) {

            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while(j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    while(j < k && nums[j] == nums[j + 1])
                        j++;

                    while(j < k && nums[k] == nums[k - 1])
                        k--;

                    j++;
                    k--;
                }
                else if(sum < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }

        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         set<vector<int>>st;
//         for(int i = 0;i<n;i++){
//             unordered_map<int,int>mp;
//             for(int j = i+1; j < n;j++){
//                 int third = -(nums[i] + nums[j]);
//                 if(mp.find(third) != mp.end()){
//                     vector<int> temp = {nums[i], nums[j], third};
//                     sort(temp.begin(),temp.end());
//                     st.insert(temp);
//                 }
//                 mp[nums[j]]++;
//             }

//         }
//         vector<vector<int>>v(st.begin(),st.end());
//         return v ;
//     }
// };


// // class Solution {
// // public:
// //     vector<vector<int>> threeSum(vector<int>& nums) {
// //         int n = nums.size();
// //         set<vector<int>>ans;
// //         unordered_map<int,int>mp;

// //         for(int i = 0; i < n;i++){
// //             mp[i] = nums[i];
// //         }
// //         for(int i = 0; i < n;i++){
// //             vector<int>temp;
// //             for(int j = i+1; j < n;j++){
// //                 int rem = -(nums[i] + nums[j]);
// //                 for(auto k : mp){
// //                     if(k.second == rem && i != j && i != k.first && j != k.first){
// //                         temp.push_back(nums[i]);
// //                         temp.push_back(nums[j]);
// //                         temp.push_back(k.second);
// //                         mp.erase(k.first);
// //                     }
// //                 }

// //             }
// //             ans.push_back(temp);
// //         }
// //         return ans;
// //     }
// // };