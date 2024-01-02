class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        int number = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            number = max(number, mp[nums[i]]);
        }
        
        vector<vector<int>> v;
        for (int i = 0; i < number; i++) {
            vector<int> st;
            for (auto& it : mp) {
                if (it.second > 0) {
                    st.push_back(it.first);
                    it.second--;
                }
            }
            v.push_back(st);
        }
        return v;
    }
};
