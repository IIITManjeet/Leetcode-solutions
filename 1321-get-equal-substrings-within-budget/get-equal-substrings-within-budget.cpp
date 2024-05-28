class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = abs(s[i] - t[i]);
        }
        int maxLen = 0;
        int currentCost = 0;
        int start = 0;
        for (int end = 0; end < n; end++) {
            currentCost += v[end];
            while (currentCost > maxCost) {
                currentCost -= v[start];
                start++;
            }
            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};
