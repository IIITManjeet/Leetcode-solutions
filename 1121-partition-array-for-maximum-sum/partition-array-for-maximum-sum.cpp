class Solution {
public:
    int solve(vector<int>& arr, int idx, int k, vector<int>& dp) {
        if (idx <= 0) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        
        int ans = 0, maxAns = 0;
        for (int j = 1; j <= k && idx - j >= 0; j++) {
            maxAns = max(maxAns, arr[idx - j]);
            ans = max(ans, solve(arr, idx - j, k, dp) + j * maxAns);
        }
        
        return dp[idx] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return solve(arr, n, k, dp);
    }
};
