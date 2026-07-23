class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        // vector<int>ans;----> now worked
        // int maxi = *max_element(nums.begin(), nums.end());
        // for(int i= 1; i <= maxi;i++){
        //     if(i > nums.size()) break;
        //     if(nums[i-1] == i) continue;
        //     else {
        //         int m = i;
        //         while(m!= nums[i]){
        //             ans.push_back(m++);
        //         }
        //     }
        // }
        // return ans[k-1];
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        while(lo<= hi){
            int mid = (lo + hi)/2;
            int missing = nums[mid] - (mid+1);
            if(missing<k){
                lo= mid +1;
            }
            else {
                hi= mid -1;
            }
        }
        return k + hi +1;
    }
};