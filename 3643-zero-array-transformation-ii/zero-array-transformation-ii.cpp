class Solution {
public:
    bool isZeroArrayAfterK(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            diff[l] -= val;
            if (r + 1 < n) {
                diff[r + 1] += val;
            }
        }
        vector<int> temp = nums;
        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr += diff[i];
            temp[i] += curr;
            if (temp[i] > 0) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size();
        int left = 0, right = q, ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isZeroArrayAfterK(nums, queries, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};