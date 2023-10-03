class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        set<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    v.insert({i,j});
                }
            }
        }
        return v.size();
    }
};