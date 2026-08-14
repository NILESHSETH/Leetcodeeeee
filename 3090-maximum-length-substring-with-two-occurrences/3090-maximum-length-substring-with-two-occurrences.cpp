class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        vector<int>v(256);
        int len = 0;
        int i = 0; 
        int j = 0;
        while(i < n){
            v[s[i] - 'a']++;
            while(v[s[i]-'a'] > 2) {
                v[s[j] - 'a']--;
                j++;

            }
            len = max(len, i-j+1);
            i++;
        }
        return len;
    }
};