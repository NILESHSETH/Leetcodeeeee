class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        map<pair<int,int>, int> mp;  
        int ext = 0;
        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i+1]) {
                ans++;
                continue;
            }
            auto key = minmax(nums[i], nums[i+1]); 
            mp[key]++;
            ext = max(mp[key], ext);
        }

        return ans + ext;
    }
};