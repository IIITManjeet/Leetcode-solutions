class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (auto& pass : details) {
            int cnt = stoi(pass.substr(11, 2));
            // cout << cnt << " ";
            if (cnt > 60) ans++;
        }
        return ans;
    }
};
