class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        map<int,int> mp;

        for(int i = 0; i < n; i++)
            mp[nums[i]]++;

        vector<int> ans;

        while(!mp.empty()) {

            for(auto it = mp.begin(); it != mp.end();) {

                ans.push_back(it->first);
                it->second--;

                if(it->second == 0)
                    it = mp.erase(it);
                else
                    ++it;
            }
        }

        return ans;
    }
};

// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>ans;

       
//         for(int i = 0; i < n;i++){
//             vector<int>temp;
//                     vector<int>vis(n,0);

//             for(int j = i; j < n;j++){
//                 if(vis[j] == 0 && nums[j] != 0) {
//                     temp.push_back(nums[j]);
//                     nums[j] = 0;
//                 }
//                 vis[j] = 1;

//             }
//             sort(temp.begin(), temp.end());
//             for(int k = 0; k < temp.size();k++) ans.push_back(temp[k]);
//         }
//         return ans;
//     }
// };