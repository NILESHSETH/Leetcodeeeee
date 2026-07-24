class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string t = "";

        for(auto i: s) {
            if(i == ' ') {
                if(t.size() > 0) {
                    st.push(t);
                    t = "";
                }
            } else {
                t.push_back(i);
            }
        }

        if(t.size() > 0)
            st.push(t);

        string output = "";
        while(!st.empty()) {
            output += st.top() + " ";
            st.pop();
        }

        output.pop_back();
        return output;
    }
};


// class Solution {
// public:
//     string trim(string s) {
//         int start = s.find_first_not_of(" \t\n\r\f\v");
//         if (start == string::npos) return "";

//         int end = s.find_last_not_of(" \t\n\r\f\v");
//         return s.substr(start, end - start + 1);
//     }

//     string reverseWords(string s) {
//         s = trim(s);
//         int n = s.size();

//         string cur = "";
//         string ans = "";

//         for (int i = n - 1; i >= 0; i--) {

//             if (s[i] == ' ') {
//                 reverse(cur.begin(), cur.end());
//                 ans += cur + " ";
//                 cur = "";
//             } else {
//                 cur += s[i];
//             }
//         }

//         reverse(cur.begin(), cur.end());
//         ans += cur;

//         return ans;
//     }
// };