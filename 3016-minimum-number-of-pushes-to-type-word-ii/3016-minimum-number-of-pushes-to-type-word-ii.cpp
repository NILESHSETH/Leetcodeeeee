class Solution {
public:
    int minimumPushes(string s) {
        // unordered_map<char,int>mp;
        // for(int i = 0; i < n;i++){

        // }
        unordered_map<char, int> mp;

        for (char c : s)
            mp[c]++;

        vector<pair<char, int>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            return a.second > b.second; // descending frequency
        });
        int n = v.size();
        int cnt = 0;
        int m = 1;
        for (int i = 0; i < n; i++) {
            if (i >= 8 && i < 16)
                m = 2;
            else if (i >= 16 && i < 24)
                m = 3;
            else if (i >= 24)
                m = 4;
            cnt += v[i].second * m;
        }
        return cnt;
    }
};