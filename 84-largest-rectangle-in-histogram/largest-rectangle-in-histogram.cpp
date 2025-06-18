class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        long long maxArea=LLONG_MIN;
        int n=h.size();
        stack<int>st;
        for(int i=0;i<=n;i++){
            int curH=(i==n?0:h[i]);
            while(!st.empty() && curH<h[st.top()]){
                int height=h[st.top()];
                st.pop();
                int w=(st.empty()?i:i-st.top()-1);
                maxArea=max(maxArea,w*height*1LL);
            }
            st.push(i);
        }
        return (int)maxArea;
        }
};