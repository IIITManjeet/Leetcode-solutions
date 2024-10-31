#define all(v) v.begin(), v.end()
class Solution {
public:
    long long f(int rInd, int fInd, vector<int>& robot, vector<int>& fctInd, vector<vector<long long>>& dp) {
        if (rInd == robot.size()) return 0;
        if (fInd == fctInd.size()) return LLONG_MAX;
        if (dp[rInd][fInd] != -1) return dp[rInd][fInd];
        long long assign_cost = abs(robot[rInd] - fctInd[fInd]);
        long long ans1 = f(rInd + 1, fInd + 1, robot, fctInd, dp);
        if (ans1 != LLONG_MAX) {
            ans1 += assign_cost;
        }
        long long ans2 = f(rInd, fInd + 1, robot, fctInd, dp);
        return dp[rInd][fInd] = min(ans1, ans2);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        sort(all(robot));
        sort(factory.begin(), factory.end());
        vector<int> fctInd;
        for (auto& f : factory) {
            for (int i = 0; i < f[1]; i++) {
                fctInd.push_back(f[0]);
            }
        }
        vector<vector<long long>> dp(n, vector<long long>(fctInd.size(), -1));
        long long result = f(0, 0, robot, fctInd, dp);
        return result == LLONG_MAX ? -1 : result;
    }
};
