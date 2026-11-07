class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        for(int i = 0; i < n;i+= 2){
            string a = to_string(nums[i]);
            string b = to_string(nums[i+1]);
            mini = min(stoi(a+b), mini);
        }
        return mini;
    }
};