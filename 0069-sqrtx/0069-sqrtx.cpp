class Solution {
public:
    int mySqrt(int x) {
        int lo = 1;
        int hi =  x;
        int ans;
        if(x==0) return 0;
        while(lo <= hi){
            long long mid = lo+ (hi-lo)/2;
            // if(mid*mid <= x){
            //      return ans =  mid;
            // }

          if(mid*mid <= x) {
            ans = mid;
            lo =mid+1;
          }
          else hi = mid-1;
        }
        return ans;
    }
};