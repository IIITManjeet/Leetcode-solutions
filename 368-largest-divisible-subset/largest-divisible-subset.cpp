class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>next(n,1),hash(n);
        int maxi=1,lastIndex=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && 1+next[prev]>next[i]){
                    next[i]=1+next[prev];
                    hash[i]=prev;
                }
            }
            if(next[i]>maxi){
                maxi=next[i];
                lastIndex=i;
            }
        }
        vector<int>temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex=hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};