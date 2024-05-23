class Solution {
public:
    int f(vector<int>& nums,int k,int ind,int mask){
        if(ind==nums.size())return mask>0?1:0;
        bool flag=true;
        int skip=f(nums,k,ind+1,mask);
        int take=0;
        for(int j=0;j<ind && flag;j++){
            flag=((1<<j) & mask)==0 || abs(nums[j]-nums[ind])!=k;
        }
        if(flag)take=f(nums,k,ind+1,mask+(1<<ind));
        return skip+take;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int mask=0;
        return f(nums,k,0,mask);
    }
};