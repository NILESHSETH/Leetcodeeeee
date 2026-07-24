class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        vector<int> temp = nums;      
        sort(temp.begin(), temp.end());

        vector<int> ans;

        for (int x : nums) {

            int idx = lower_bound(temp.begin(), temp.end(), x) - temp.begin();

            ans.push_back(idx);
        }

        return ans;
    }
};