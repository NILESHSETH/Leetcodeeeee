class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for (auto i : nums)
            mp[i]++;

        for (auto& it : mp) {
            it.second = min(it.second, 2);
        }

        int i = 0;
        int cnt = 0;

        for (auto it : mp) {
            int k = it.second;

            while (k) {
                nums[i++] = it.first;
                k--;
            }

            cnt += it.second;
        }

        return cnt;
    }
};

// \int ans[n];
// // WRONG: Variable-length array; not standard C++.
// // Also unnecessary because the problem requires modifying nums in-place.

// for(auto it : mp){
//     it.second = min(it.second, 2);
// }
// // WRONG: 'it' is a copy, so changing it.second does not change mp.
// // Use: for(auto &it : mp)

// ans[i++] = it.first;
// // WRONG: You are modifying ans instead of nums.
// // The answer must be written back into nums in-place.