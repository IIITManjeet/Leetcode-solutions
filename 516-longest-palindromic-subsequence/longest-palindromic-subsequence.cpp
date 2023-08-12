class Solution {
public:
    int lps(string s,int i,int j,vector<vector<int>>&dp){
        if(i==j)return 1;
        if(dp[i][j]!=0)return dp[i][j];
        if(i>j)return 0;
        if(s[i]==s[j])
        dp[i][j]=lps(s,i+1,j-1,dp)+2;//for palindrom maintainence
        else dp[i][j]=max(lps(s,i+1,j,dp),lps(s,i,j-1,dp));//for getting max length from i->j-1 and i-1->j
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size()));
        // return lps(s,0,s.size()-1,dp);
        for (int i = s.size() - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][s.size() - 1];
    }
};