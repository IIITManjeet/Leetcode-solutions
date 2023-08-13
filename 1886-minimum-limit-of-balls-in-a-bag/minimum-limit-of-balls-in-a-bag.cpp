class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int r=*max_element(nums.begin(),nums.end());
        int l=1;
        int ans=r;
        while(l<r){
            int penalty=(l+r)/2;
            int op=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>penalty){
                     if(nums[i]%penalty==0){
                    op+=nums[i]/penalty-1;
                }else{
                    op+=nums[i]/penalty;
                }
                }
            }
            if(op<=maxOperations){
                ans=penalty;
                r=penalty;
            }
            else{
                l=penalty+1;
            }
        }
        return ans;
    }
};