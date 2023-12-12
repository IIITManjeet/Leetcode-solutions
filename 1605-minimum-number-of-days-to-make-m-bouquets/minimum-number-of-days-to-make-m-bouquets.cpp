class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans=-1,l=1,r=1e9,n=bloomDay.size();
        if ((long)m * (long)k > n) return -1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int c=0,t=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid)c++;
                else c=0;
                if(c==k){
                    t++;
                    c=0;
                }
            }
            if(t>=m){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};