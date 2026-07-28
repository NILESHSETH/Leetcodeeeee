class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if (n <= 1)
            return s;
        string ans = "";
        if (n % 2 != 0) {
            int m = n / 2;
            string k = "";
            for (int i = 0; i < m; i++) {
                k += s[i];
            }
            sort(k.begin(), k.end());
            ans += k;
            k = ans;
            reverse(k.begin(), k.end());
            ans += s[m];

            ans += k;
        } else {
            int m = n / 2;
            string k = "";
            for (int i = 0; i < m; i++) {
                k += s[i];
            }
            sort(k.begin(), k.end());
            ans += k;
            k = ans;
            reverse(k.begin(), k.end());
            ans += k;
        }
        return ans;
    }
};