class Solution {
public:
    bool isHappy(int n) {

        unordered_map<int, int> mp;
        bool flag = true;
        while (flag) {
            mp[n]++;
            vector<int> v;
            while (n > 0) {
                v.push_back(n % 10);
                n = n / 10;
            }
            int sum = 0;
            for (int i = 0; i < v.size(); i++) {
                sum += v[i] * v[i];
            }
            if (sum == 1)
                return true;
            n = sum;
            // int p = 1;
            // for(int i = 0; i < v.size();i++){
            //     n+= p*v[i];
            //     p*= 10;
            // }
            if (mp.find(n) != mp.end()) {
                flag = false;
            }
        }
        return false;
    }
};

// class Solution {
// public:
//     bool isHappy(int n) {
//         if(n==1) return 0;
//         bool f = true;
//         int k = n;
//         while(f){
//             vector<int>v;
//             while(k> 0){
//                 v.push_back(k%10);
//                 k = k/10;
//             }
//             int i= 0;
//             int p = 1;
//             int num = 0;
//             if()
//             while(i = v.size()-1){
//                 num += p*v[i++];
//                 p*= 10;
//             }

//         }

//     }
// };