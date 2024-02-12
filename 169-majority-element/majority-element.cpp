class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=nums[0],cnt=1;
        for(int i=1;i<nums.size();i++){
            int it=nums[i];
            if(cnt==0){
                maj=it;
                cnt++;
            }else if(maj==it){
                cnt++;
            }
            else cnt--;
        }
        return maj;
    }
};