class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, maxlen = 0;
        unordered_map<int,int>mpp;
        while(r < n){
            mpp[nums[r]]++;
            if(mpp.size() > 2){
                if(mpp.size() > 2){
                    mpp[nums[l]]--;
                }
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            if(mpp.size() <= 2 ) maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};