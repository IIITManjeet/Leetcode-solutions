class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        multiset<int>st;
        for(int n:nums){
            int sq=n*n;
            st.insert(sq);
        }
        vector<int>v(st.begin(),st.end());
        return v;
    }
};