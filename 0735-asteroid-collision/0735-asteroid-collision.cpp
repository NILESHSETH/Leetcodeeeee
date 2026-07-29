class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size();
        vector<int>vis;
        for(int i = 0; i < n;i++){
            if(nums[i] > 0) vis.push_back(nums[i]);
            else {
                // condition like the right most elmenet is smaller and is positve
                while(!vis.empty() && vis.back() >0 && vis.back() < abs(nums[i])) vis.pop_back();
                if(!vis.empty() && vis.back() == abs(nums[i])){
                    vis.pop_back();
                }
                else if(vis.empty() || vis.back() < 0) vis.push_back(nums[i]);

            }
        }
        return vis;
        
    }
};


// wrong code
// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& p) {
//         int n = p.size();
//         stack<int> st;
//         vector<pair<int, int>> nums;
//         for (int i = 0; i < n; i++) {
//             nums.push_back({p[i], i});
//         }

//         // now we have formed the pair vertices, now we are aware fo the index
//         // of each element

//         for (int i = 0; i < n; i++) {
//             int ele = nums[i].first;

//             if (ele < 0) {
//                 while (!st.empty()) {
//                     int num = nums[st.top()].first;
//                     if (abs(num) == ele) {
//                         st.pop();
//                         // nums[st.top()].first = 1002;
//                         // nums[st.top()].second = -1;
//                         continue;
//                     } else if (num > abs(ele)) {
//                         st.pop();
//                     } else {
//                         continue;
//                     }
//                 }
//             }

//             st.push(nums[i].second);
//         }
//         vector<int> ans;
//         for (int i = 0; i < n; i++) {
//             if (nums[i].first!= 1002)
//                 ans.push_back(nums[i]);
//         }
//         return ans;
//     }
// };