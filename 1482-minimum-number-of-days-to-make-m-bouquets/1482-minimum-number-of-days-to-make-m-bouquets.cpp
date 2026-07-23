class Solution {
public:
    int possible(vector<int>& nums, int day, int m, int k) {
        long long cnt = 0;
        long long nb = 0;
        int n = nums.size();
       
        for (int i = 0; i < n; i++) {
            if (nums[i] <= day)
                cnt++;
            else {
                nb += (cnt / k);
                cnt = 0;
            }
        }

        nb += (cnt / k);
        return nb;
    }

    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        // int hi = *max_element(nums.begin(), nums.end());
        // int lo = *min_element(nums.begin(), nums.end());
        // int ans = INT_MAX;
        // if(m*k > n) return -1;
        // while (lo <= hi) {
        //     int mid = lo + (hi - lo) / 2;
        //     long long cnt = 0;

        //     for (int i = 0; i < n; i++) {
        //         cnt += (1.0 * nums[i]) / mid;
        //     }

        //     if (cnt / k <= m) {
        //         lo = mid + 1;
        //     } else {
        //         lo = mid + 1;
        //         ans = min(ans, mid);
        //     }
        // }
        // return ans;
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        // for (int i = mini; i <= maxi; i++) {
        //     if (possible(nums, i, m, k))
        //         return i;
        // }
        int lo = mini;
        int hi = maxi;
        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(possible(nums,mid,m,k) >= m){
                ans = mid;
                hi = mid -1;
            }
            else{
                lo = mid+1;
            }

        }
        return ans;
    }
};