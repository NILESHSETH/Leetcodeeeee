class Solution {
public:
    void helper(int ind, int target, vector<vector<int>>&ans, vector<int>&ds,vector<int>& nums) {
        int n = nums.size();
        if (ind == n) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }
        // now first pick the element at the index ind
        if (nums[ind] <= target) {
            ds.push_back(nums[ind]);
            helper(ind , target - nums[ind], ans, ds, nums);
            ds.pop_back();
        }
        // now not taking the elment
        helper(ind+1, target, ans, ds,nums);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector <vector<int>> ans;
        vector<int> ds;
        helper(0, target, ans, ds,nums);
        return ans;
    }
};