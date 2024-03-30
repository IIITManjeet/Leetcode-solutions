class Solution {
public:
    int sub(vector<int>& X,int k){
        int i=0,j=0;
        int n=X.size(),ans=0;
        unordered_map<int,int>mp;
        while(i<n){
            mp[X[i]]++;
            while(mp.size()>k){
                mp[X[j]]--;
                if(mp[X[j]]==0){
                    mp.erase(X[j]);
                }
                j++;
            }
            ans+=i-j+1;
            i++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& X, int k) {
        return sub(X, k) - sub(X, k - 1);
    }
};