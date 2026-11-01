class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(nums.begin(),nums.end());

        int sum = 0;
        for(int i = 0; i < n;i++) sum += abs(nums[i]- mini);
        // int avg = sum/n;
        // int cnt =0;
        // for(int i =; i < )
        return sum;
        
    }
};