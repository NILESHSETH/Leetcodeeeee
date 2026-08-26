// class Solution {
// public:
//     static bool cmp(string a, string b) {
//     if(a.size() != b.size())
//         return a.size() < b.size();

//     return a < b;
// }
//     string shortestBeautifulSubstring(string s, int k) {
//         int n = s.size();
//         int i =0;
//         int j = i+1;
//         int cnt = 0;
//         vector<string>v;
//         if(s[i] == '1') cnt++;
//         while(j < n){
//             if(s[j] == '1') cnt++;
//             if(cnt == k){
//                 string q = "";
//                 for(int p =i; p <= j; p++){
//                     q+= s[p];
//                 }
//                 v.push_back(q);
//                 if(s[i] == '1') cnt--;
//                 i++;
//                 j = i+1;
//                 continue;
//             }
//             j++;
//         }
//         sort(v.begin(),v.end(),cmp);
//         return v[0];
//     }
// };

class Solution {
public:
    static bool cmp(string a, string b) {
        if(a.size() != b.size())
            return a.size() < b.size();
        return a < b;
    }

    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        vector<string> v;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '1') cnt++;
                if (cnt == k) {
                    v.push_back(s.substr(i, j - i + 1));
                    break;
                }
            }
        }

        if (v.empty()) return "";

        sort(v.begin(), v.end(), cmp);
        return v[0];
    }
};