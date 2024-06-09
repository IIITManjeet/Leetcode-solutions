class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int mod[k];
        int curSum=0;
        memset(mod,0,sizeof(mod));
        for(int i=0;i<nums.size();i++){
            curSum+=nums[i];
            mod[((curSum%k)+k)%k]++;
        }
        int res=0;
        for(int i=0;i<k;i++){
            if(mod[i]>1){
                res+=(mod[i]*(mod[i]-1))/2;
            }
        }
        res+=mod[0];
        return res;
    }
};