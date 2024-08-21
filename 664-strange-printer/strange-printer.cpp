class Solution {
public:
    int solve(int i, int j, string& s, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        dp[i][j] = solve(i, j - 1, s, dp) + 1;
        for (int k = i; k < j; ++k) {
            if (s[k] == s[j]) {
                dp[i][j] = min(dp[i][j], solve(i, k, s, dp) + solve(k + 1, j - 1, s, dp));
            }
        }
        
        return dp[i][j];
    }

    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, s, dp);
    }
};
