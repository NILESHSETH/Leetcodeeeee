class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int i = 0;

        sum = nums[0];
        for (i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }


        sort(nums.begin(), nums.end());

        int target = sum;

        for (int num : nums) {
            if (num == target) {
                target++;          
            } 
            else if (num > target) {
                break;             \
            }
        }

        return target;
    }
};