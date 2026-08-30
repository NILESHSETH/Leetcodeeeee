class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int remove = -1; remove < n;remove++){
            vector<int>arr;
            vector<int>pref;
            vector<int>suf;
            int p = 0;
            int s = 0;
            int i = 0 ;
            int j = n-1;
            while(i < n){
                if(i != remove){
                    arr.push_back(nums[i]);
                    p  = gcd(p,nums[i]);
                    pref.push_back(p);
                }
                i++;
            }
            while(j >= 0){
                if(j != remove){
                    s = gcd(s,nums[j]);
                    suf.push_back(s);
                }
                j--;
            }
            reverse(suf.begin(), suf.end());
            s = 0;
            int m = arr.size();
            for(int i = 0; i < m-1;i++){
                // int lg = 0;
                // int rg  = 0;
                // for(int j = 0; j <= i;j++) lg = gcd(lg,arr[j]);
                // for(int j = i+1; j < m;j++) rg = gcd(rg, arr[j]);
                if(pref[i] == suf[i+1]) s++;
            }
            cnt  = max(s, cnt);
            
        }
        return cnt;
        
    }
};