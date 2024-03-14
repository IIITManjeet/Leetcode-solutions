class Solution {
public:
    int sum(vector<int>& nums,int goal){
        int cursum=0,total=0,s=0;
        for(int e=0;e<=nums.size()-1;e++){
            cursum+=nums[e];
            while(cursum>goal && s<=e){
                cursum-=(nums[s++]);
            }
            total+=(e-s+1);
        }
        return total;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sum(nums,goal)-sum(nums,goal-1);
    }
};