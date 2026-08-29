class Solution {
    typedef long long ll;
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long ans = (ll)nums[n-1]*nums[n-2]*100000ll;
        ans = max(ans, (ll)nums[0]*nums[n-1]*-100000ll);
        ans = max(ans, (ll)nums[0]*nums[1]*100000ll);
        return ans;
        
    }
};


// class Solution {
// public:
//     long long maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         vector<int>f;
//         vector<int>l;
//         for(int i = 0; i < 3;i++)f.push_back(nums[i]);
//         for(int i = n-1; i >= n-3; i--) l.push_back(nums[i]);
//         int cf = 0;// count zero firts
//         int cnf = 0;// count negative first

//         int cl = 0;// count zero last
//         int cnl = 0;// count negtive last
//         for(auto i : f) {
//             if(i == 0) cf++;
//             if(i  <= ) cnf++;
//         }
//         for(auto i : l){
//              if(i == 0) cl++;
//              if(i < 0) clf ++;
//         }
//         long long pf = 1;
//         long long pl = 1;
//         if(cf >= 2) pf = 0;
//         else {
//             if(cf == 1){// measn it have one zero
//                 if(cnf == 1){ // measn it has one negative so muntply with biggest negative
//                     for(int i = 0; i < 3; i++){
//                         if(f[i] == 0) pf = pf*-1e5;
//                         else pf = pf*f[i];
//                     }
//                 }
//                 else if(cnf == 2 || cnf == 0){// measn 2 neagtive thet will cancel each ther and both positive will also cancel ach other
//                     for(int i = 0; i < 3;i++){
//                         if(f[i] == 0) pf = pf*1e5;
//                         else pf = pf*f[i];
//                     }
//                 }
              
//             }
            
//         }


        
//     }
// };