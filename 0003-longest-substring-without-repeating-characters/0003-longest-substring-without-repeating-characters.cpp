class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n  =s.size();
        unordered_map<char,int>mp;
        int l = 0, r = 0, maxlen = 0, len = 0;
        while(r < n){
            mp[s[r]]++;
            if(mp[s[r]] > 1){
                for(int i = l ; i < r; i++){
                    if(s[i] == s[r]){
                        mp[s[i]]--;
                        l = i+1;
                        break;
                    }
                     mp[s[i]]--;
                }
            }
            len = r-l+1;
            r++;
            maxlen = max(maxlen , len);
        }
        return maxlen;
    }
};