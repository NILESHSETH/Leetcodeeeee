class Solution {
public:
    int trap(vector<int>& nums) {
        // making the next greater element array
        int n = nums.size();
        // stack<int>st;
        // vector<int>rightmax(n);
        // for(int i = n-1; i >= 0; i--){
        //     while(!st.empty() && nums[i] > st.top()) st.pop();
        //     int num = nums[i];
        //     rightmax[i] = st.empty()? -1:st.top();
        //     st.push(num);
        // }
        // st = stack<int>();
        // vector<int>leftmax(n);
        // for(int i = 0; i <n;i++){
        //     while(!st.empty() && nums[i] >st.top()) st.pop();
        //     //now we have the smaller element
        //     int num = nums[i];
        //     leftmax[i] = st.empty() ?-1:st.top();
        //     st.push(num);
        // }
        // // now we have the left and rge righr max element
        vector<int> leftmax(n);
        vector<int> rightmax(n);
        leftmax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            leftmax[i] = max(leftmax[i - 1], nums[i]);
        }

        rightmax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightmax[i] = max(rightmax[i + 1], nums[i]);
        }

        long long total = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < rightmax[i] && nums[i] < leftmax[i]) {
                total += min(rightmax[i], leftmax[i]) - nums[i];
            }
        }
        return total;
    }
};