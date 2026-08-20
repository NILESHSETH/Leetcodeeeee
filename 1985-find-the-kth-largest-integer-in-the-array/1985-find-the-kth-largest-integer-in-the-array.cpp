class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {

        int n = nums.size();

        // CHANGE:
        // We cannot convert these strings to int/long long
        // because some numbers are too large.
        // So compare them as strings:
        // 1. Different length -> longer number is larger
        // 2. Same length -> normal string comparison
        sort(nums.begin(), nums.end(), [](string a, string b) {

            if(a.size() != b.size())
                return a.size() < b.size();

            return a < b;
        });

        int cnt = 1;

        for(int i = n - 1; i >= 0; i--) {

            if(cnt == k)
                return nums[i];

            cnt++;
        }

        return "";
    }
};