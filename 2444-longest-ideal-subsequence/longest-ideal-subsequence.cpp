#define all(v) v.begin(), v.end()
class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int>dp(27);
        int n = s.length();
        for (int i = n - 1; i >= 0; i--) {
            char cc = s[i];
            int idx = cc - 'a';
            int maxi = -INT_MAX;
            int left = max((idx - k), 0);
            int right = min((idx + k), 26);
            for (int j = left; j <= right; j++) {
                maxi = max(maxi, dp[j]);
            }
            dp[idx] = maxi + 1;
        }
        return *max_element(all(dp));
    }
};