class Solution {
public:
    bool check(vector<int>& nums, vector<int>& c,int mid){
        unordered_map<int,int>l;
        for(int i=0;i<mid;i++)l[c[i]]=i;
        if(l.size()!=nums.size())return false;// check if all are found or not
        int cnt=0;
        for(int i=0;i<mid;i++){
            if(i==l[c[i]]){
                if(cnt<nums[c[i]-1])return false;
                else cnt-=nums[c[i]-1];
            }else cnt++;
        }
        return true;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& c) {
        int n=nums.size();
        int m=c.size();
        int l=0,r=m+1;
        while(l<r){
            int mid=(l+r)>>1;
            if(check(nums,c,mid))r=mid;
            else l=mid+1;
        }
        return r==m+1?-1:r;
    }
};