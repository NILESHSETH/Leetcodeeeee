class Solution {
public:
    typedef long long ll;
    int maxProduct(vector<int>& nums) {

        ll n = nums.size();
        int maxi = INT_MIN;
        int prev = 1;
        int suf = 1;
        for(int i = 0; i < n;i++){


            if(prev ==0) prev = 1;
            if(suf ==0) suf = 1;

            prev *= nums[i];
            suf *= nums[n-i-1];
            maxi = max(maxi,max(prev,suf));
        }

        return maxi;














































        // ll n = nums.size();
        // ll i = 0;
        // ll j = 0;
        // ll prod = 1;
        // ll it = min_element(nums.begin(), nums.end(), [](int a, int b) {
        //     if (a < 0)
        //         return false;
        //     if (b < 0)
        //         return true;
        //     return a < b;
        // });
        // ll maxi = it;

        // while (i < n) {
        //     if (nums[i] <= 0) {
        //         while (j != i) {
        //             prod = prod / nums[j];
        //             j++;
        //             if (i == j)
        //                 prod = -(prod / nums[j]);
        //             j++;
        //         }
        //     }
        //     prod = prod * nums[i];
        //     i++;
        //     maxi = max(maxi, prod);
        // }
        // return maxi;
    }
};