class Solution {
public:
    string resultingString(string s) {
        int n=s.length();
        string new_s="";
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            st.push(s[i]);
            else if((abs(s[i]-st.top())==1) || ((int)s[i]==97 && (int)st.top()==122) || ((int)s[i]==122 && (int)st.top()==97))
            st.pop();
            else
            st.push(s[i]);
        }
        while(!st.empty())
        {
            new_s+=st.top();
            st.pop();
        }
        reverse(new_s.begin(),new_s.end());
        return new_s;
    }
};