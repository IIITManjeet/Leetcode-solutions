class Solution {
public:
    bool helper(int mid,vector<int>& weights,int days){
        int count = 1, sum = 0;
        
        for(int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if (sum > mid) {
                count++;
                sum = weights[i];
            }
        }
        if (count <= days)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(), weights.end()),r=0,ans=0;
        for(auto it:weights)r+=it;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(helper(mid,weights,days)){
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