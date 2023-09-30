class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int min1=INT_MIN,n=nums.size();
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<min1)return true;
            while(!s.empty() && nums[i]>s.top()){
                min1=s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};