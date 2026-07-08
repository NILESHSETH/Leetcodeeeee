class Solution {
public:
    int dr(int num){
        int mx = 0;
        int mn = 9;
        while(num > 0){
            int d = num%10;
            mx = max(mx,d);
            mn = min(mn,d);
            num /= 10;
        }
        return mx - mn;
    }
    int maxDigitRange(vector<int>& nums) {
        int mrange = 0;
        for(int num : nums){
            mrange = max(mrange, dr(num));
        }
        int sum = 0;
        for(int num : nums){
            if(dr(num) == mrange){
                sum+= num;
            }
        }
        return sum;
    }
};