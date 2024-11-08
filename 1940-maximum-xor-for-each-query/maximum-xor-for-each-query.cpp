class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int x=0;
        for(auto it:nums)x^=it;
        int k=(1<<maximumBit)-1;
        vector<int>ans;
        int i=0;
        for(auto it:nums){
            ans.push_back(x^k);
            x^=(nums[nums.size()-i-1]);
            i++;
        }
        return ans;
    }
};