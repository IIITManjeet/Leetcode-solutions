class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = 1;
        for(int i = 1; i < n; i++){
            int max_len = 0;
           for(int j = 0; j < i; j++){
               if(nums[j] < nums[i]){ 
                   max_len = max(max_len, dp[j]);
               }
               dp[i] = 1 + max_len;
           }
        }
        return *max_element(dp.begin(), dp.end());; 
    }
};