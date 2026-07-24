class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // // HashMap to store mapping from characters of s -> characters of t
        // unordered_map<char, char> mp1;

        // // HashMap to store reverse mapping from characters of t -> characters of s
        // // This prevents two different characters in s from mapping to the same character in t
        // unordered_map<char, char> mp2;

        // // Traverse both strings together
        // for (int i = 0; i < s.size(); i++) {

        //     // If s[i] has already been mapped before
        //     // and its mapped character is different from the current t[i],
        //     // then mapping is inconsistent.
        //     if (mp1.count(s[i]) && mp1[s[i]] != t[i])
        //         return false;

        //     // If t[i] has already been mapped before
        //     // and its mapped character is different from the current s[i],
        //     // then two characters of s are trying to map to the same character of t.
        //     if (mp2.count(t[i]) && mp2[t[i]] != s[i])
        //         return false;

        //     // Store/update the mapping s[i] -> t[i]
        //     mp1[s[i]] = t[i];

        //     // Store/update the reverse mapping t[i] -> s[i]
        //     mp2[t[i]] = s[i];
        // }

        // // No conflicts found, strings are isomorphic
        // return true;
        if(s.size() != t.size()) return false;
        int n = s.size();
        unordered_map<char,char>st;
        unordered_map<char,char>ts;
        for(int i = 0; i < n;i++){
            if(st.count(s[i]) && st[s[i]] != t[i]) return false;
            if(ts.count(t[i]) && ts[t[i]] != s[i]) return false;
            st[s[i]] = t[i];
            ts[t[i]] = s[i];
        }
        return true;
    }
};