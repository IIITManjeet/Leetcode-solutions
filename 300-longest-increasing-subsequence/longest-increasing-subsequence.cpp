class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>next(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i]){
                    next[i]=max(next[i],1+next[prev]);
                }
            }
        }
        return *max_element(next.begin(),next.end());
    }
};
