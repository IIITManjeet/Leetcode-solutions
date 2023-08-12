class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        int n=nums1.size();int m=nums2.size();
        vector<int>prev(n+1,0);
        for(int i=1;i<=n;i++){
            vector<int>cur(n+1,0);
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]){
                    cur[j]=1+prev[j-1];
                }
                else cur[j]=0;
                ans=max(ans,cur[j]);
            }
            prev=cur;
        }
        return ans;
    }
};