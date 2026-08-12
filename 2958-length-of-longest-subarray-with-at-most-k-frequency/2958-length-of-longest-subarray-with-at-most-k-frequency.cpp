class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> vis;

        int maxi = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            vis[nums[i]]++;

            while (vis[nums[i]] > k) {
                vis[nums[j]]--;
                j++;
            }

            maxi = max(maxi, i - j + 1);
        }

        return maxi;
    }
};