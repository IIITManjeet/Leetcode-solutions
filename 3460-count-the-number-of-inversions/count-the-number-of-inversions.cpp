#define rep(i, a, b) for (int i = a; i <= b; i++)
const int MOD = 1e9 + 7;
typedef vector<long> vi;
typedef vector<vi> vvi;
#define F first
#define S second

int dp[301][401];

class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& r) {
        memset(dp, 0, sizeof(dp));
        map<int, int> reqMap;
        for (auto it : r) {
            reqMap[it[0] + 1] = it[1];
        }
        dp[0][0] = 1;
        int len = 1;
        while (len <= n) {
            int cur = 0;
            while (cur < 401) {
                int newPos = 0;
                while (newPos < len) {
                    int prev = cur - newPos;
                    if (prev >= 0) {
                        (dp[len][cur] += dp[len - 1][prev]) %= MOD;
                    }
                    newPos++;
                }
                cur++;
            }
            if (reqMap.find(len) != reqMap.end()) {
                int req = reqMap[len];
                int cur = 0;
                while (cur < 401) {
                    if (cur != req) {
                        dp[len][cur] = 0;
                    }
                    cur++;
                }
            }
            len++;
        }
//         len = 1;
//         while (len <= n) {
            
//             len++;
//         }
        int ans = 0;
        rep(i, 0, 400) {
            (ans += dp[n][i]) %= MOD;
        }
        return ans;
    }
};