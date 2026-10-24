// class Solution {
// public:
//     string largestNumber(vector<int>& nums) {
//         map<int,vector<int>>mp;
//         int n = nums.size();

//         for(int i = 0; i < nums.size(); i++){
//             vector<int>v;

//             int k = nums[i];
//             while(k > 0){
//                 v.push_back(k%10);
//                 k = k/10;
//             }
//             vector<int>temp = mp[v[v.size() -1]];// now we find the that first digit vector
//             temp.push_back(nums[i]);// pussshing the new element
//             sort(temp.begin(), temp.end());// shorting
//             mp[v[v.size() -1]] = temp; //now again redefing it
//         }




//         string ans;
//         for(auto vec : mp)
//         {
//             int n = vec.size();
//             for(int i  =0; i < n; i++) ans+= vec[i];

//         }
//     }
// };
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) + to_string(b) >
                   to_string(b) + to_string(a);
        });
        if (nums[0] == 0) return "0";

        string ans;

        for (int num : nums) {
            ans += to_string(num);
        }

        return ans;
    }
};