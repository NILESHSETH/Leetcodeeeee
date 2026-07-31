class Solution {
public:
    void help(int ind, vector<int>& nums, set<vector<int>>& ans,
              vector<int>& dis) {
        int n = nums.size();
        if (ind == n) {
            ans.insert(dis);
            return;
        }
        dis.push_back(nums[ind]);
        help(ind + 1, nums, ans, dis);
        dis.pop_back();

        help(ind + 1, nums, ans, dis);
        // for(int i = ind; i < n;i++){
        //     if(i > ind && nums[i] == nums[i-1]) continue;
        //     dis.push_back(nums[i]);
        //     help(i+1,nums,ans,dis);
        //     dis.pop_back();
        // }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<int> dis;
        help(0, nums, ans, dis);
        vector<vector<int>>v;
        for(auto it : ans) v.push_back(it);
        return v;
    }
};