class Solution {
public:
    vector<int> findnse(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            // CHANGED: <=  ---> >=
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nse;
    }

    vector<int> findpsee(vector<int>& nums) {
        int n = nums.size();
        vector<int> psee(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return psee;
    }


    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse = findnse(nums);
        vector<int> pse = findpsee(nums);
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]*(nse[i] - pse[i] -1));
        }
        return maxi;
    }
};