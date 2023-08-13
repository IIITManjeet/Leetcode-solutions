class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int r=*max_element(nums.begin(),nums.end());
        int l=1,penalty,op=0;
        while(l<r){
            penalty=((r-l)>>1)+l;
            op=0;
            for(auto &i: nums){
                op += ((i-1)/penalty);
            }
            if(op>maxOperations){
                l = penalty+1;
            }else{
                r = penalty;
            }
        }
        return l;
    }
};