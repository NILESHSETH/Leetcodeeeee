class Solution {
public:
    string trim(string s) {
        int l = 0, r = s.size() - 1;

        while (l <= r && s[l] == ' ')
            l++;

        while (r >= l && s[r] == ' ')
            r--;

        return s.substr(l, r - l + 1);
    }
    int myAtoi(string s) {
        s = trim(s);

        if (s.empty())
            return 0;

        int i = 0;
        int sign = 1;

        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        long long ans = 0;

        while (i < s.size() && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            if (sign == 1 && ans > INT_MAX)
                return INT_MAX;

            if (sign == -1 && -ans < INT_MIN)
                return INT_MIN;

            i++;
        }

        return sign * ans;
    }
};