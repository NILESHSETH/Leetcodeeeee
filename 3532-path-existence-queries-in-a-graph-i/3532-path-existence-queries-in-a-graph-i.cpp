// class Solution {
// public:
//     vector<bool> pathExistenceQueries(int n, vector<int>& vec, int maxDiff, vector<vector<int>>& nums) {
//         vector<bool> ans(nums.size());

//         for (int i = 0; i < nums.size(); i++) {
//             int u = nums[i][0];
//             int v = nums[i][1];

//             int dif = abs(vec[u] - vec[v]);

//             if (dif <= maxDiff)
//                 ans[i] = true;
//             else
//                 ans[i] = false;
//         }

//         return ans;
//     }
// };
int comp[100000];
class Solution {
public:
    static vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        const int qz=queries.size();
        vector<bool> ans(qz);
        int prev=nums[0], cid=0;
        comp[0]=cid;
        for(int i=1; i<n; i++){
            const int curr=nums[i];
            cid+=(prev+maxDiff<curr);
            comp[i]=cid;
            prev=curr;
        }
        for (int i=0; i<qz; i++){
            const int x=queries[i][0], y=queries[i][1];
            ans[i]=comp[x]==comp[y];
        }
        return ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();