class Solution {
public:
    int countValidPrefixes(string s) {
        int o = 0;
        int z = 0;
        int c = 0;
        for(auto i : s){
            if(i == '0') z++;
            if(i == '1') o++;
            if(abs(o-z) <= 1) c++;
        }
        return c;
    }
};