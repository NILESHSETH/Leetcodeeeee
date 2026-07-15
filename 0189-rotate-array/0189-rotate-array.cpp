class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        int l = k;
        stack<int>st;
        for(auto it : nums) st.push(it);
        vector<int>ans;
        while(k--){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        for(int i = 0; i < n-l;i++){
            ans.push_back(nums[i]);
        }
        nums = ans;
    }
};
