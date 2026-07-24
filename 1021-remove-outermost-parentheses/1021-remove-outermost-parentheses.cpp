class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int cnt = 0;
        string ans = "";
        string temp = "";
        for(int i = 0; i < n;i++){
            if(s[i] == '(') {
                cnt++;
                temp += s[i];
            }
            else{
                cnt--;
                temp += s[i];
            }

            if(cnt == 0){
                ans += temp.substr(1,temp.size() -2);
                temp = "";
            }
                
            
        }
        return ans;
    }
};