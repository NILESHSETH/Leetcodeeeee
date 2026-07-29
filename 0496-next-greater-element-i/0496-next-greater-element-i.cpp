class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ans(n);
        stack<int> st;

        ans[n - 1] = -1;
        st.push(nums2[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        vector<int> v;

        for (int i = 0; i < nums1.size(); i++) {
            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            int index = it - nums2.begin();
            v.push_back(ans[index]);
        }

        return v;
    }
};