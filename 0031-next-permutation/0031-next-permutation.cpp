class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        // you have to relace the mininum exixting number after that na na..
        // mans if you want the next number greater than that then you need find
        // that nest smallest greater number than the standing number...means if
        // you wnat to find greater number than 54310---> you only want the
        // number to whome you can replace after that ones position
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            for (int i = n - 1; i >= 0; i--) {
                // now we need to find the nxt elment greater than the the
                // lelement at index ind
                if (nums[i] > nums[ind]) {
                    swap(nums[ind], nums[i]);
                    break;
                }
            }
            reverse(nums.begin() + ind + 1, nums.end());
        }
    }
};