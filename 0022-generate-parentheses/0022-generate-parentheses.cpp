class Solution {
public:
    void helper(int open, int close, int n, string cur, vector<string>&ans){
        if(open == close && open + close == 2*n){
            ans.push_back(cur);
            cur = "";
            return;
        }
        if(open < n){
            helper(open + 1, close, n , cur +"(" , ans);
        }
        if(close < open){
            helper(open , close +1,n, cur +")", ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string cur = "";
        helper(0,0,n,cur,ans);

        return ans;
  
        
    }
};