class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(auto i : nums) mp[i]++;
        for(int i = 1;i <= 1e5;i++){
            int m = k*i;
            if(mp.find(m) == mp.end()) return m;
        }
        return -1;
    }
};