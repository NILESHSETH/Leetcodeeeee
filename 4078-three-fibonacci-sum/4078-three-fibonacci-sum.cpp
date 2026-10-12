class Solution {
public:
    bool threeFibonacciSum(int n) {
        long long f = 0;
        long long s = 1;

        while (true) {
            if ((f + s) * 2 == n)
                return true;
            if ((f + s) > n)
                return false;

            long long t = f;
            f = s;
            s = t + s;
        }
    }
};