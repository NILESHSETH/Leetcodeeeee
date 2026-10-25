class Solution {
public:
    bool checkPerfectNumber(int n) {
        long long sum = 0;
        for (long long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                sum += i;
                if (i != n / i)
                    sum += n / i;
            }
        }
        sum -= n;
        if (sum == n)
            return true;
        else
            return false;
    }
};