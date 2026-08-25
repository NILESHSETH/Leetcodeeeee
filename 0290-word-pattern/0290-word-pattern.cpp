class Solution {
public:
// i am not chaking the reverse logic


//like a = dog b = dog but this should not happen..
    bool wordPattern(string pat, string s) {
        int n = pat.size();
        int m = s.size();
        int j = 0;

        unordered_map<char, string> mp;

      
        unordered_map<string, char> rev;

        for(int i = 0; i < n; i++) {

            // CHANGE 2:
            // If we still need a word but s is already finished,
            // then pattern has more characters than s has words.
            if(j >= m) return false;

            char temp = pat[i];
            string k = "";
            while(j < m && s[j] != ' ') {
                k += s[j];
                j++;
            }

            if(mp.find(temp) != mp.end()) {

                if(mp[temp] != k) return false;
            }
            else {
                // CHANGE 4:
                // If this word is already mapped to another character,
                // then two characters cannot represent the same word.
                if(rev.find(k) != rev.end()) return false;

                // New character -> word mapping
                mp[temp] = k;

                // New word -> character mapping
                rev[k] = temp;
            }

            // CHANGE 5:
            // Only skip the space if there actually is a space.
            if(j < m) j++;
        }

        // CHANGE 6:
        // Make sure s doesn't contain extra words.
        //
        // Example:
        // pat = "ab"
        // s = "dog cat fish"
        //
        // After processing "dog" and "cat", j will still be
        // before the end of s, so return false.
        return j >= m;
    }
};