class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int indpos = 0;
        int indneg = 1;
        vector<int>ans(n,0);
        for(int i = 0; i < n;i++){
            if(nums[i] >0){
                ans[indpos] = nums[i];
                indpos+=2;
            }
            else if(nums[i] < 0){
                ans[indneg] = nums[i];
                indneg+=2;
            }
        }
        return ans;
    }
};