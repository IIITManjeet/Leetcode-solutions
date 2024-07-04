class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()<=4)return 0;
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        for(int l=0,r=n-4;l<4;l++,r++){
            diff=min(diff,nums[r]-nums[l]);
        }
        return diff;   
    }
};