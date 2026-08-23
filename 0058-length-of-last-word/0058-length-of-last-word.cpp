class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;

        while (i <= j && s[i] == ' ')
            i++;

        while (i <= j && s[j] == ' ')
            j--;

        s = s.substr(i, j - i + 1);
        i = s.size() - 1;
        int cnt = 0;

        while (i >= 0) {
            if(int(s[i]) ==32 )break;
            else cnt++;
            i--;
        }
        return cnt;
    }
};