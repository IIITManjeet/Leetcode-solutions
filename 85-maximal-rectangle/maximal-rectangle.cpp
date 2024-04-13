class Solution {
public:
    int maximalRectangle(vector<vector<char>>& m) {
        int row=m.size();
        int col=m[0].size();
        int maxArea=0;
        vector<int>h(col+1,0);
        for (const auto& row : m) {
            for (int i = 0; i < col; i++) {
                h[i] = (row[i] == '1') ? h[i] + 1 : 0;
            }
            stack<int> stk;
            for (int i = 0; i < h.size(); i++) {
                while (!stk.empty() && h[i] < h[stk.top()]) {
                    int ht = h[stk.top()];
                    stk.pop();
                    int w = stk.empty() ? i : i - stk.top() - 1;
                    maxArea = max(maxArea, ht * w);
                }
                stk.push(i);
            }
        }
        return maxArea;
    }
};