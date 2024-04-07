class Solution {
public:
    int n = 0;
    vector<vector<int>> dp;

    bool f(string& s, int i, int cnt) {
        if (i >= n) return cnt == 0; 
        if (cnt < 0) return false;
        if (dp[i][cnt] != -1) return dp[i][cnt];

        bool isValid = false;
        if (s[i] == '*') {
            isValid |= f(s, i + 1, cnt + 1);
            isValid |= f(s, i + 1, cnt - 1);
            isValid |= f(s, i + 1, cnt);
        } else {
            int newCnt = cnt + (s[i] == '(' ? 1 : -1);
            isValid |= f(s, i + 1, newCnt);
        }

        return dp[i][cnt] = isValid;
    }

    bool checkValidString(string s) {
        n = s.size();
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        return f(s, 0, 0);
    }
};
