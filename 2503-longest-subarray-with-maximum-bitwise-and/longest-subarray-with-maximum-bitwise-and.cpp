class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxAnd=*max_element(nums.begin(),nums.end());
        int maxLength=0;
        int cnt=0;
        for(int i:nums){
            if(i==maxAnd){
                cnt++;
                maxLength=max(maxLength,cnt);
            }
            else cnt=0;
        }
        return maxLength;
    }
};