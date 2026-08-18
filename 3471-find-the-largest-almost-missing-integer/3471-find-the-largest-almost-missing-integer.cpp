class Solution {
public:
    int largestInteger(vector<int>& A, int k) {
        int n = A.size(), freq[51] = {};

        for (int x : A)
            freq[x]++;

        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (k == n || (freq[A[i]] == 1 &&
                (k == 1 || i == 0 || i == n - 1))) {
                ans = max(ans, A[i]);
            }
        }

        return ans;
    }
};
// class Solution {
// public:
//     int largestInteger(vector<int>& nums, int k) {
//         // int n = nums.size();
//         // int f = nums[0];
//         // int l = nums[n - 1];
//         // map<int, int> mp;
//         // for (auto i : nums)
//         //     mp[i]++;
//         // if (k == 1) {
//         //     for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
//         //         if(it->second == 1) return it->first;
//         //     }
//         // }
//         // if (k == n) {
//         //     return mp[mp.size() - 1];
//         // }

//         // // if(l > f && mp[l == 1]) return l;
//         // // else if(l < f && mp[f == 1]) return f;
//         // if(mp[l==1] && mp[f==1]) {
//         //     return (l>f?l:f);
//         // }
//         // if(mp[l==1]){
//         //     return l;
//         // }
//         // else if(mp[f] == 1) return f;

//         // if(mp[l] >1 && mp[f] > 1) return -1;
//         // return -1;

//     }
// };