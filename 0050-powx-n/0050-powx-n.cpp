class Solution {
public:
    double myPow(double x, long long n) {
        double ans = 1;
        long long k = n;
        if(n < 0) n = -1*n;
        while(n > 0){
            if(n%2==0){
                x*= x;
                n = n/2;
            }
            else{
                ans = ans *x;
                n = n-1;
            }
        }
        if(k<0) return 1.0/ans;
        return ans;
    }
};

// class Solution {
// public:
//     double helper(double x, long long n) {
//         if (n == 0)
//             return 1;
//         if (n == 1)
//             return x;

//         return x * helper(x, n - 1);
//     }

//     double myPow(double x, int n) {
//         long long N = n;

//         if (N >= 0)
//             return helper(x, N);
//         else
//             return 1.0 / helper(x, -N);
//     }
// };