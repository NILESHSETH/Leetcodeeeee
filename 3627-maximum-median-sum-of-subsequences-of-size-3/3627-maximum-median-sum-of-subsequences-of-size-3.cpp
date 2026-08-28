class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        deque<int> dq;
        for(int i = 0; i < n;i++)dq.push_back(nums[i]);
        int times = n/3;
        long long sum = 0;
        while(times--){
            dq.pop_back();
            sum += dq.back();
            dq.pop_back();
            dq.pop_front();
        } 
        return sum;

        
    }
};