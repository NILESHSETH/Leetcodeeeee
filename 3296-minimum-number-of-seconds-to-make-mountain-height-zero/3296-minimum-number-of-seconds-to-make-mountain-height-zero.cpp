class Solution {
public:
    bool check(int height, vector<int>&nums, long long time){
        int n = nums.size();
        long long tot = 0;
        for(int i = 0;i < n;i++){
            long long hi = sqrtl((2.0L*time)/nums[i] + (0.5)*(0.5)) - 0.5L;
            tot += hi;
        }
        if(tot >= height) return true;
        else return false;



    }
    long long minNumberOfSeconds(int height, vector<int>& nums) {
        long long lo = 1;
        long long hi = 1LL*(*max_element(nums.begin(), nums.end()))*(1LL*height*(height+1)/2);
        while(lo < hi){
            long long mid = lo + (hi-lo)/2;
            if(check(height, nums,mid)){
                hi = mid;
            }
            else {
                lo = mid+1;

            }
        }
        return lo;

    }
};