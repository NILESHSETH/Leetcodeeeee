class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            int k = nums[i];
            while (k > 0) {
                int d = k % 10;
                sum += d;
                k = k / 10;
            }
            mp[sum].push_back(nums[i]);
        }

        vector<int> dif;
        for (auto &it : mp) {
            sort(it.second.begin(), it.second.end());
            for (int x : it.second) dif.push_back(x);
        }

        unordered_map<int, int> target;
        for (int i = 0; i < n; i++) target[dif[i]] = i;

        // CHANGED: replaced `abs(dif[nums[i]] - i)` summing. That indexed
        // dif by the VALUE (out of bounds) and distance isn't the swap count anyway.
        // NEW: count cycles in the permutation. A cycle of length L needs L - 1 swaps.
        vector<bool> vis(n, false);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] || target[nums[i]] == i) continue;
            int len = 0, j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = target[nums[j]]; 
                len++;
            }
            cnt += len - 1; 
        }
        return cnt;
    }
};
// class Solution {
// public:
//     int minSwaps(vector<int>& nums) {
//         vector<pair<int, int>> v;
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             int ds = 0;
//             int k = nums[i];
//             while (k > 0) {
//                 int r = k % 10;
//                 ds += r;
//                 k = k / 10;
//             }
//             v.push_back({nums[i], ds});
//         }
//         int cnt = 0;
//         sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
//             return a.second < b.second;
//         });
//         for(int i = 0; i< n;i++){
//             if(v[i].first != nums[i]) cnt++;
        
//             // {
//             //     if(v[i].second() )
//             // }
//         }
//         int m = ceil(cnt/2.0);
//         return m;
//     }
// };