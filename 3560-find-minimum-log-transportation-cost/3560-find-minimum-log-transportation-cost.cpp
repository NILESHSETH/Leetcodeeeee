class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long cost = 0;
        if(n >k ) cost = (long long)k*(n-k);
        if(m > k ) cost = (long long)k*(m-k);
        // if(n > k && n&k ==0) cost = k*(n-n/k);
        // if(m > k && m%k == 0) cost = (m-m/k)*k;
        return cost;
        
    }
};