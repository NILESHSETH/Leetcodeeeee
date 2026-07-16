class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) { 
        int n = nums.size();

        vector<int> pg(n);
        pg[0] = nums[0];
        int mxi = nums[0];
        for(int i = 1; i < n;i++){
            mxi = max(nums[i], mxi);
            pg[i] = gcd(nums[i],mxi);

        }
        int i = 0;
        int j = n-1;
        long long sum = 0;
        sort(pg.begin(), pg.end());
        // for(int i = 0; i < n/2;i++){
        //     int j = n-i-1;
        //     s+= gcd(nums[i],nums[j]);
        // }
        while(i < j){
            sum+= gcd(pg[i],pg[j]);
            i++;
            j--;
        }
        return sum;
    }
};

// class Solution {
// public:
//     int gcd(int a, int b) {
//         while (b != 0) {
//             int temp = b;
//             b = a % b;
//             a = temp;
//         }
//         return a;
//     }

//     long long gcdSum(vector<int>& nums) { 
       

//         for(int i = 1; i < n; i++){
//             pg[i] = gcd(pg[i-1], nums[i]);
//         }

//         sort(pg.begin(), pg.end());

//         int i = 0;
//         int j = n-1;
//         long long sum = 0;

//         while(i < j){
//             sum += gcd(pg[i], pg[j]);
//             i++;
//             j--;
//         }

//         return sum;
//     }
// };