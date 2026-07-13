class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for (auto it : nums)
            st.insert(it);
        vector<pair<int, int>> v;
        int rank = 1;
        for (auto it : st) {
            v.push_back({rank++, it});
        }

      
        for (int i = 0; i < n; i++) {
            int k = nums[i];
            int low = 0, high = v.size() - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (v[mid].second == k) {
                    nums[i] = v[mid].first;
                    break;
                } else if (v[mid].second < k)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return nums;
    }
};