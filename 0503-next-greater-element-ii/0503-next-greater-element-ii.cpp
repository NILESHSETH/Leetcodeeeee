class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int m = nums.size();
        for(int i = 0; i< m;i++){
            nums.push_back(nums[i]);
        }
        int n = nums.size();
        stack<int>st;
        for(int i  =n-1; i >= 0; i--){
            while(!st.empty() && st.top()<=  nums[i]) st.pop();
            int num = nums[i];
            nums[i] = st.empty() ? -1:st.top();
            st.push(num);
        }
        vector<int>ans(m);
        for(int i = 0; i< m;i++){
            ans[i] = nums[i];
        }
        return ans;
        
    }
};