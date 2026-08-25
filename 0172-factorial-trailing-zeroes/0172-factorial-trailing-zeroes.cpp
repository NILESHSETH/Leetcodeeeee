class Solution {
public:
long long helper(int n) {
    if (n <= 1) return 1;
    return n * helper(n - 1);
}
    int trailingZeroes(int n) {
        // if(n==0) return 0;
        // vector<int>v;
        // long long fact = helper(n);
        // while(fact > 0){
        //     v.push_back(fact%10);
        //     fact /= 10;
        // }
        
        int cnt = 0;
        // for(int i = 0; i < v.size(); i++){
        //     if(v[i] == 0) cnt++;
        //     if(v[i] != 0) break;
        // }
        while(n >= 5){
            n = n/5;
            cnt+= n;

        }
        return cnt;

        
    }
};