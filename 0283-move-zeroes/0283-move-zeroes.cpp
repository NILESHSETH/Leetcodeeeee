class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;

        while (j < n) {
            while (i < n && nums[i] == 0)
                i++;

            if (i == n)
                break;

            nums[j] = nums[i];
            i++;
            j++;
        }

        while (j < n)
            nums[j++] = 0;
    }
};