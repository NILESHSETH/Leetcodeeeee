class Solution {
public:
    string generateTag(string s) {

        int start = 0;
        while (start < s.size() && s[start] == ' ')
            start++;

        int end = s.size() - 1;
        while (end >= 0 && s[end] == ' ')
            end--;

        s = s.substr(start, end - start + 1);
        string ans = "#";
        // ans += tolower(s[0]);
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                cnt++;
                continue;
            }
            if (cnt) {
                ans += toupper(s[i]);
                cnt = 0;
            } else
                ans += tolower(s[i]);
        }
        return ans.substr(0, 100);
    }
};