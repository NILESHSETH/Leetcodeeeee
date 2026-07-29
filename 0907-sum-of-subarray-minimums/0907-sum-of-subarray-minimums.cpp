// class Solution {
// public:
// int mod = 1e9+ 7;

//     vector<int>findnse(vector<int>&nums){
//         int n = nums.size();
//         vector<int>nse(n);
//         stack<int>st;
//         for(int i = n-1 ; i >= 0; i--){
//             while(!st.empty() && nums[st.top()] <= nums[i])st.pop();
//             nse[i] = st.empty()?n:st.top();
//             st.push(i);
//         }
//         return nse;
//     }
//        vector<int>findpsee(vector<int>&nums){
//         int n = nums.size();
//         vector<int>pse(n);
//         stack<int>st;
//         for(int i = 0; i < n; i++){
//             while(!st.empty() && nums[st.top()] > nums[i])st.pop();
//             pse[i] = st.empty()?-1:st.top();
//             st.push(i);
//         }
//         return pse;
//     }


//     int sumSubarrayMins(vector<int>& nums) {
//         int n = nums.size();

//         vector<int>nse(n);
//         nse = findnse(nums);
//         vector<int>psee(n);
//         psee = findpsee(nums);
//         long long total = 0;
//         for(int i = 0; i< n;i++){
//             int left = i - psee[i];
//             int right = nse[i]  -i;
//             total = (right*left*1LL*nums[i])%mod;
//         }
//         return total%mod;





//         // int n = nums.size();
//         // int mini = INT_MAX;
//         // long long sum = 0;
//         // for (int i = 0; i < n; i++) {

//         //     int prev = INT_MAX;
//         //     for (int j = i; j < n; j++) {
//         //         prev = min(nums[j], prev);
//         //         sum += prev;
//         //     }
//         // }
//         // return sum%mod;
//     }
// };
class Solution {
public:
    int mod = 1e9 + 7;

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

    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();

        vector<int> nse = findnse(nums);
        vector<int> psee = findpsee(nums);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;

            // CHANGED:
            // total = (right*left*1LL*nums[i])%mod;

            total = (total + (left * right % mod) * nums[i]) % mod;
        }

        return total % mod;
    }
};