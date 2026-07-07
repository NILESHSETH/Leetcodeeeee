class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // if(k== 0) return 0;
        // int x,y;
        // int l  =0, r= 0;
        // int sumx = 0,cntx = 0;
        // int sumy = 0,cnty = 0;
        // while(r<n){
        //     sumx += nums[r];
        //     while(sumx > k){
        //         sumx-= nums[l];
        //         l++;
        //     }
        //     if(sumx <= k) cntx++;
        //     r++;
        // }
        // l = 0, r = 0;
        // while(r<n && k > 0){
        //     sumy+= nums[r];
        //     while(sumy > k){
        //         sumy-= nums[l];
        //         l++;
        //     }
        //     if(sumy<= k-1) cnty++;
        //     r++;
        // }
        // return cntx - cnty;
        int cnt = 0;
        for(int i = 0; i <n ;i++){
                    long long sum = 0;

            for(int j = i; j < n;j++){
                sum += nums[j];
                if(sum == k){
                    cnt++;
                }
            }
        }
        return cnt;
      
    }
};