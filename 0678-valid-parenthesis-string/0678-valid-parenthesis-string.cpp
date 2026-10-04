class Solution {
public:
    bool checkValidString(string s) {
        int l = 0;
        int r = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                l++;
                r++;
            }
            else if (s[i] == ')') {
                l--;
                r--;
            }
            else {
                l--;
                r++;
            }

            if (r < 0)
                return false;

            l = max(0, l);
        }

        return l == 0;
    }
};