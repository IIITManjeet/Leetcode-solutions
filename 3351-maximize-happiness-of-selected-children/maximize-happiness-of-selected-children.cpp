class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.begin(),h.end(),greater<int>());
        int n=h.size();
        long long cnt=0;
        long long ans=0;
        while(k--){
            
            ans+=(h[cnt]-cnt>=0?h[cnt]-cnt:0);
            cnt++;
        }
        return ans;
    }
};