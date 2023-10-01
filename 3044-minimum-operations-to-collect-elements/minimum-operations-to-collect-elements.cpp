class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int>s;
        int n=nums.size();
        int cnt=0;
        int t=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<=k){
                s.insert(nums[i]);
            }
            if(s.size()==k)return n-i;
        }
        return n;
    }
};