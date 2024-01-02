class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> st;
        int i = 0;
        while ( i < k ) st.insert(nums[i++]);
        ans.push_back(*st.rbegin());
        int n = nums.size();
        for ( int i = k ; i < n ; i++ ) {
            auto ind = st.find(nums[i-k]);
            st.erase(ind); st.insert(nums[i]);
            ans.push_back(*st.rbegin());
        }
        return ans;
    }
};