class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int N = ring.length();
        int M = key.length();
        
        vector<vector<int>> dp(N, vector<int>(M, INT_MAX));
        
        vector<vector<int>> char_pos_map(26, vector<int>());
        for(int i = 0; i < N; ++i) {
            int cur_char = ring[i] - 'a';
            char_pos_map[cur_char].push_back(i);
        }
        
        int res = INT_MAX;
        for(int i = 0; i < M; ++i){
            int cur_char = key[i] - 'a';
            for(int cur_pos : char_pos_map[cur_char]){
                if(i == 0) {
                    dp[cur_pos][0] = min(cur_pos, N - cur_pos) + 1;
                } else {
                    int pre_char = key[i - 1] - 'a';
                    for(int pre_pos : char_pos_map[pre_char]){
                        int diff = min(abs(cur_pos - pre_pos), N - abs(cur_pos - pre_pos));
                        dp[cur_pos][i] = min(dp[cur_pos][i], dp[pre_pos][i - 1] + diff + 1);
                    }
                }
                if(i == M - 1)
                    res = min(res, dp[cur_pos][M - 1]);
            }
        }

        return res;
    }
};