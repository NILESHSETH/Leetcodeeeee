class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;
        multimap<int, char, greater<int>> mp;
        for (auto x : freq)
            mp.insert({x.second, x.first});
        string ans = "";
        for(auto i : mp){
            int cnt = i.first;
            int cha = i.second;
            while(cnt--){
                ans+= cha;
            }
        }
        return ans;
        
    }
};