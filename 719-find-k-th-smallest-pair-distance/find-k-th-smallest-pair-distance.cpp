class Solution {
public:
    int helper(vector<int>&nums,int k,int diff){
        int cnt=0;
        int j=0,n=nums.size();
        for(int i=0;i<n;i++){
            while(j<n && (nums[j]-nums[i])<=diff){
                j++;
            }
            cnt+=(j-i-1);
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,h=nums[n-1]-nums[0];
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(helper(nums,k,mid)>=k){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};