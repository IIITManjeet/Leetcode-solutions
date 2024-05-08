class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        map<int, int, greater<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[score[i]] = i;
        }
        vector<string> ans(n);
        auto it = mp.begin();
        if (it != mp.end()) {
            ans[it->second] = "Gold Medal";
            it++;
        }
        if (it != mp.end()) {
            ans[it->second] = "Silver Medal";
            it++;
        }
        if (it != mp.end()) {
            ans[it->second] = "Bronze Medal";
            it++;
        }
        int rank = 4;
        while (it != mp.end()) {
            ans[it->second] = to_string(rank++);
            it++;
        }
        return ans;
    }
};