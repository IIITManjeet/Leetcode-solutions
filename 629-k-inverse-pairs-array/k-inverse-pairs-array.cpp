class Solution {
public:
    int dp[1001][1001]={1};
    int kInversePairs(int n, int k) {
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                for(int p=0;p<=min(i - 1, j);p++){
                    dp[i][j]=(dp[i][j]+dp[i-1][j-p])%1000000007;
                }
            }
        }
        return dp[n][k];
    }
};