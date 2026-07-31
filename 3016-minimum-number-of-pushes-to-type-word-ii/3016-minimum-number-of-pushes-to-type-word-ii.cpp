// class Solution {
// public:
//     int minimumPushes(string nums) {
//         // unordered_map<char,int>mp;
//         // for(int i = 0; i < n;i++){

//         // }
//         unordered_map<char, int> mp;

//         for (char c : s)
//             mp[c]++;

//         vector<pair<char, int>> v(mp.begin(), mp.end());

//         sort(v.begin(), v.end(), [](auto& a, auto& b) {
//             return a.second > b.second; // descending frequency
//         });
//         int n = v.size();
//         int cnt = 0;
//         int i = 0;
//         int m= 1;
//         while(i <n){


//         }
//     }

// };
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> charCount(26, 0);

        for(char ch : word) {
            charCount[ch - 'a']++;
        }

        sort(charCount.begin(), charCount.end(), greater<int>());

        int minPushCount = 0;

        for(int i = 0; i < 26; i++) {
            minPushCount += charCount[i] * (i / 8 + 1);
        }

        return minPushCount;
    }
};