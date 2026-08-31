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
        long long sum = 0;
        long long mod = 1e9 + 7;

        for(int i = 0; i < nums.size(); i++) {
            int width = nums[i] % 10;
            long long d = nums[i] / 10;

            vector<int> v;

            while(d > 0) {
                v.push_back(d % 10);
                d /= 10;
            }

            reverse(v.begin(), v.end());

            int x = 0;
            for(int j = 0; j < width; j++) {
                x = x * 10 + v[j];
            }

            int y = 0;
            for(int j = width; j < v.size(); j++) {
                y = y * 10 + v[j];
            }

            sum = (sum + power(x, y)) % mod;
        }

        return sum;
    }
};