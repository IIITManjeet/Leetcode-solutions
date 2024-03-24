class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            int f[26] = {0};
            for (int j = i; j < s.size(); ++j) {
                int index = s[j] - 'a';
                f[index]++;
                if (f[index] <= 2) {
                    ans = max(ans, j - i + 1);
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};
