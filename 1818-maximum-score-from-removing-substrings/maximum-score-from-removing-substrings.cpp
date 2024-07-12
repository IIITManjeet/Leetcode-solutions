class Solution {
public:
    string f(const string& ipt, const string& tgt) {
        stack<char> st;
        for (char ch : ipt) {
            if (ch == tgt[1] && !st.empty() && st.top() == tgt[0]) {
                st.pop();
            } else {
                st.push(ch);
            }
        }
        string rem;
        while (!st.empty()) {
            rem += st.top();
            st.pop();
        }
        reverse(rem.begin(), rem.end());
        return rem;
    }
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        string highString = x > y ? "ab" : "ba";
        string lowString = highString;
        reverse(lowString.begin(),lowString.end());
        string first = f(s, highString);
        int rem=(s.size() - first.size()) / highString.size();
        ans += rem* max(x, y);
        string second =f(first, lowString);
        rem=(first.size() - second.size()) /lowString.size();
        ans += rem* min(x, y);
        return ans;
    }
};