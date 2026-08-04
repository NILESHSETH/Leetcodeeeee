class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        // int maxi = *max_element(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        vector<int>ans;
        for(int i = 0; i < n;i++){
            while(mini != nums[i]) ans.push_back(mini++);
            mini++;
        }
        return ans;
        
    }
};