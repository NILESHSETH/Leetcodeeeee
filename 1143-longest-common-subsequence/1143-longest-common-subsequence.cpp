class Solution {
public:
    int f(int ind1, int ind2, string sa, string sd, vector<vector<int>>&dp){
        if(ind1 <0|| ind2<0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(sa[ind1] == sd[ind2]) return dp[ind1][ind2] = 1+f(ind1-1,ind2-1,sa,sd,dp);
        else  return dp[ind1][ind2] = max(f(ind1-1,ind2,sa,sd,dp),f(ind1,ind2-1,sa,sd,dp));



    }
    int longestCommonSubsequence(string sa, string sd) {
        int n = sa.size();
        int m = sd.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j = 0; j <= m;j++) dp[0][j] =0;
        for(int i = 0; i <= n;i++) dp[i][0] = 0;
        for(int ind1 = 1; ind1 <= n;ind1++){
            for(int ind2= 1; ind2 <= m;ind2++){
                 if(sa[ind1-1] == sd[ind2-1])  dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];
                  else dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);

            }
        }
        return dp[n][m];

        
    }
};