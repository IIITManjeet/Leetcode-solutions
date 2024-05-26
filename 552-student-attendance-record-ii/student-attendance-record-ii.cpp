class Solution {
public:
    int N = 0;
    int MOD = 1e9 + 7;

    int f(int day, int absences, int late, vector<vector<vector<int>>>& dp) {
        if (day == N) return 1;
        if (dp[day][absences][late] != -1) return dp[day][absences][late];
        int total = 0;
        (total += f(day + 1, absences, 0, dp)) %= MOD;
        if (absences < 1) {
            (total += f(day + 1, absences + 1, 0, dp)) %= MOD;
        }
        if (late < 2) {
            (total += f(day + 1, absences, late + 1, dp)) %= MOD;
        }
        
        return dp[day][absences][late] = total;
    }

    int checkRecord(int n) {
        N = n;
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 0, 0, dp);
    }
};
