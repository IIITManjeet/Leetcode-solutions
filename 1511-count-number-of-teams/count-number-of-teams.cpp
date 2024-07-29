class Solution {
public:
    int numTeams(vector<int>& rating) {
        return countTeams(rating) + countTeams(vector<int>(rating.rbegin(), rating.rend()));
    }

private:
    int countTeams(const vector<int>& rating) {
        int n = rating.size();
        unordered_map<int, unordered_map<int, int>> memo;

        auto dp = [&](int i, int mem_num, const auto& dp_ref) -> int {
            if (mem_num == 3) return 1;
            if (memo[i].count(mem_num)) return memo[i][mem_num];

            int result = 0;
            for (int j = i + 1; j < n; ++j) {
                if (rating[j] > rating[i]) {
                    result += dp_ref(j, mem_num + 1, dp_ref);
                }
            }
            return memo[i][mem_num] = result;
        };

        int teams = 0;
        for (int i = 0; i < n; ++i) {
            teams += dp(i, 1, dp);
        }
        return teams;
    }
};
