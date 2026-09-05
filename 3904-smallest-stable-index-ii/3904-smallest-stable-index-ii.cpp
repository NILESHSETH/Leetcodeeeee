class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int n = nums.size();
        int pref[n];
        int suf[n];
        int maxi = nums[0];
        for(int i = 0; i < n;i++){
            maxi = max(nums[i],maxi);
            pref[i] = maxi;
        }
        int mini= nums[n-1];
        for(int i= n-1; i >=0 ; i--){
            mini = min(nums[i],mini);
            suf[i] = mini;
        }
        for(int i = 0; i < n;i++){
            if(pref[i] - suf[i] <= k) return i;
        }
        return -1;
    }
};