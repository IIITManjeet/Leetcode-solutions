class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0 && find(nums.begin(),nums.end(),-nums[i])!=nums.end())ans=max(ans,nums[i]);
        }
        return ans==INT_MIN?-1:ans;
    }
};