class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> even;
        priority_queue<int> odd;
        for(int i=0;i<nums.size();i++){
            if(i%2==0) even.push(nums[i]);
            else odd.push(nums[i]);
        }
        
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                nums[i] = even.top();
                even.pop();
            }else{
                nums[i] = odd.top();
                odd.pop();
            }
        }
        
        return nums;
    }
};