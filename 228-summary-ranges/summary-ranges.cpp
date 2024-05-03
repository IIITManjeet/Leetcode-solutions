class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;
        
        int start = nums[0], end = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == end + 1) {
                end = nums[i];
            } else {
                if (start == end) {
                    ans.push_back(to_string(start));
                } else {
                    ans.push_back(to_string(start) + "->" + to_string(end));
                }
                start = end = nums[i];
            }
        }
        if (start == end) {
            ans.push_back(to_string(start));
        } else {
            ans.push_back(to_string(start) + "->" + to_string(end));
        }
        
        return ans;
    }
};