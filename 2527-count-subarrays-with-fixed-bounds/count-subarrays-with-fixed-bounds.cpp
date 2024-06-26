class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minPosition=-1,maxPosition=-1,leftBound=-1;long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK)leftBound=i;
            if(nums[i]==minK)minPosition=i;
            if(nums[i]==maxK)maxPosition=i;
            ans+=max(0,min(minPosition,maxPosition)-leftBound);
        }
        return ans;
    }
};