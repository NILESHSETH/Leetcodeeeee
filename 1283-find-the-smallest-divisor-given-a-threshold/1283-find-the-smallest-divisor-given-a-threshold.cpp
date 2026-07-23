class Solution {
public:
    int possible( vector<int>&nums, int k, int target){
        int n = nums.size();
        int cnt = 0;
        for(int i = 0;i < n;i++){
            cnt += ceil(nums[i]*1.0/k);
        }
        return cnt;
    }
    int smallestDivisor(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 1;
        int hi = *max_element(nums.begin(),nums.end());
        int ans= hi;
        if(target == n) return hi;
        while(lo<= hi){
            int mid = lo + (hi - lo)/2;
            if(possible(nums,mid,target) <= target) {
                ans = min(ans,mid);
                hi = mid-1;
            }
            else lo = mid +1;
        }
        return ans;
    }
};