class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;
        
        int ind = -1;
        for(int i = 0; i< n-1;i++){
            if(nums[i]> nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind == -1) return true;
        for (int i = ind + 1; i < n - 1; i++) {
           if(nums[i] > nums[i+1]){
            flag = false;
            break;
           }
        }
        if(nums[n-1] > nums[0]) flag =  false;

        return flag;
        //  int n = nums.size();
        // bool fg = true;

        // int j = -1;

        // for (int i = 0; i < n - 1; i++) {
        //     if (nums[i] > nums[i + 1]) {
        //         j = i;
        //         break;
        //     }
        // }

        // if (j == -1) return true;

        // // check remaining part is sorted
        // for (int i = j + 1; i < n - 1; i++) {
        //     if (nums[i] > nums[i + 1]) {
        //         fg = false;
        //         break;
        //     }
        // }

        // // circular condition
        // if (nums[n - 1] > nums[0]) fg = false;

        // return fg;
    }
};