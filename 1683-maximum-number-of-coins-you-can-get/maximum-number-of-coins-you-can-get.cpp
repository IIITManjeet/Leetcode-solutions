class Solution {
public:
    int maxCoins(vector<int>& p) {
        sort(p.begin(),p.end(),greater<int>());
        int ans=0;
        int x=p.size();
        for(int i=0;i<x;i+=2){
            ans+=p[i+1];
            x-=1;
        }
        return ans;
    }
};