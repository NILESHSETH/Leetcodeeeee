class Solution {
public:
  long long power(long long x, long long y) {
        long long ans = 1;
        long long mod = 1e9 + 7;

        while(y > 0) {
            if(y & 1)
                ans = ans * x % mod;

            x = x * x % mod;
            y /= 2;
        }

        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        long long mod = 1e9 + 7;
        long long sum = 0;
        for(int i = 0; i < n;i++){
            int width = nums[i]%10;
            long long d = floor(nums[i]*1.0/10);
            vector<int>v;
            while(d > 0){
                v.push_back(d%10);
                d = d/10;
            }
            reverse(v.begin(), v.end());
            int x = 0;
            int p = 1;
            for(int j = width -1 ; j >= 0; j--){
                x+= p*v[j];
                p = p*10;
            }
            int y  = 0;
            p = 1;
         
            for(int j = v.size() -1; j >=width; j--){
                y+= p*v[j];
                p = p*10;
            }
           sum = (sum + power(x, y)) % mod;        }
        return sum;
        
    }
};