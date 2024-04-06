class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int openCount = 0;
        unordered_map<int, bool> toRemove;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++openCount;
            } else if (s[i] == ')') {
                if (openCount > 0) {
                    --openCount;
                } else {
                    toRemove[i] = true;
                }
            }
        }
        openCount = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '(') {
                if (openCount == 0) {
                    toRemove[i] = true;
                } else {
                    --openCount;
                }
            } else if (s[i] == ')') {
                ++openCount;
            }
        }
        string ans = "";
        for (int i = 0; i < s.size(); ++i) {
            if (!toRemove.count(i)) {
                ans += s[i];
            }
        }

        return ans;
    }
};
