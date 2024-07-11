class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> st;
        vector<int> pair(n);
        for (int i = 0; i < n; ++i) {
            char cur=s[i];
            if (cur == '(') {
                st.push(i);
            }
            if (cur == ')') {
                int j = st.top();
                st.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }
        string ans;
        for (int i = 0, del = 1; i < n;i += del) {
            char cur=s[i];
            if (cur == '(' || cur == ')') {
                i = pair[i];
                del = -del;
            } else {
                ans += cur;
            }
        }
        return ans;
    }
};