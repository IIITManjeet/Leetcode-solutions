class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>next(n,1),cnt(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && next[i]<1+next[prev]){
                    next[i]=1+next[prev];
                    cnt[i]=cnt[prev];
                }else if(nums[prev]<nums[i] && next[i]==1+next[prev]){
                    cnt[i]+=cnt[prev];
                }
            }
        }
        int max=*max_element(next.begin(),next.end());
        int no=0;
        for(int i=0;i<n;i++){
            if(next[i]==max)no+=cnt[i];
        }
        return no;
    }
};