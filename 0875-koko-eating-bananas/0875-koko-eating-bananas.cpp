class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int n = nums.size();
        if(n==h) return *max_element(nums.begin(), nums.end());
        sort(nums.begin(),nums.end());

        long long lo = 1;
        long long hi = *max_element(nums.begin(), nums.end());
        long long  ans = INT_MAX;

        while( lo <= hi){
            long long mid= lo + (hi-lo)/2;
            long long cnt = 0;
            for(int i = 0; i < n;i++){
                cnt += ceil(1.0*nums[i]/mid);
            }
            if(cnt<= h){
                ans = min(ans,mid);
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};