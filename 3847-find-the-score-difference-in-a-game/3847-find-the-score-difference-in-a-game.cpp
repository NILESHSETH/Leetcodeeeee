class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(2,0);
        int cnt = 0;
        for(int i = 0; i < n;i++){
            int temp = v[0];
            if(nums[i]%2 != 0){
              swap(v[0], v[1]);
                cnt++;
            }
            if(((i+1)%6)== 0){
                swap(v[0], v[1]);
                cnt++;
            }
            v[0] += nums[i];
        }
        return cnt%2 == 0? v[0] - v[1] : v[1] - v[0];
        
    }
};