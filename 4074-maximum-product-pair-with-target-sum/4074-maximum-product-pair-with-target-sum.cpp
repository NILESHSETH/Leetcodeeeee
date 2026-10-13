class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (nums[i] + nums[j] == target && nums[i] > nums[j]) {
                    ans.push_back({nums[i] * nums[j], i, j});
                }
            }
        }

        sort(ans.begin(), ans.end());

        if (!ans.empty()) {
            return {ans.back()[1], ans.back()[2]};
        }

        return {-1, -1};
    }
};
