class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        vector<int> lazy(n + 1, 0);
        for (auto& query : queries) {
            int l = query[0], r = query[1];
            lazy[l] -= 1;
            if (r + 1 < n) lazy[r + 1] += 1;
        }
        int current = 0;
        for (int i = 0; i < n; i++) {
            current += lazy[i];
            nums[i] += current;
            if (nums[i] > 0) return false;
        }
        return true; 
    }
};
