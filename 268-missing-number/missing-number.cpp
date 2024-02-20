class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int>s;
        for(int &num:nums)s.insert(num);
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<=n;i++){
            if(s.find(i)==s.end()){
                ans=i;
            }
        }
        return ans;
    }
};