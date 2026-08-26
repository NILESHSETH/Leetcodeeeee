class Solution {
public:

    void helper(int ind, int end, int cnt, long long sum,vector<int>& nums,vector<vector<long long>>& v) {

        if(ind == end) {
            v[cnt].push_back(sum);
            return;
        }
        helper(ind + 1, end, cnt, sum, nums, v);
        helper(ind + 1, end, cnt + 1,
               sum + nums[ind], nums, v);
    }

    int minimumDifference(vector<int>& nums) {

        int n = nums.size();
        int half = n / 2;

        long long total = 0;

        for(int x : nums)
            total += x;
        vector<vector<long long>> left(half + 1);
        vector<vector<long long>> right(half + 1);

        helper(0, half, 0, 0, nums, left);

        helper(half, n, 0, 0, nums, right);
        for(int i = 0; i <= half; i++)
            sort(right[i].begin(), right[i].end());

        long long ans = LLONG_MAX;
        for(int cnt = 0; cnt <= half; cnt++) {
            int need = half - cnt;

            for(long long x : left[cnt]) {

                long long target = total / 2 - x;

                auto it = lower_bound(
                    right[need].begin(),
                    right[need].end(),
                    target
                );

                if(it != right[need].end()) {

                    long long sum1 = x + *it;
                    long long sum2 = total - sum1;

                    ans = min(ans, abs(sum1 - sum2));
                }

                if(it != right[need].begin()) {

                    --it;

                    long long sum1 = x + *it;
                    long long sum2 = total - sum1;

                    ans = min(ans, abs(sum1 - sum2));
                }
            }
        }

        return ans;
    }
};