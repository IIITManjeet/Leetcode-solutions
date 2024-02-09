class Solution {
public:
    int n;
    int f(int ind, int prevInd, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == n) return 0;
        if (dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];
        int len = 0;
        if (prevInd == -1 || nums[ind] > nums[prevInd]) {
            len = 1 + f(ind + 1, ind, nums, dp);
        }
        len = max(len, f(ind + 1, prevInd, nums, dp));
        return dp[ind][prevInd+1] = len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0, -1, nums, dp);
    }
};
