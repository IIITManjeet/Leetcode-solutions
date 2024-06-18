class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<pair<int,int>>val;
        val.push_back({0,0});
        for(int i=0;i<d.size();i++)val.push_back({d[i],p[i]});
        sort(val.begin(),val.end());
        for(int i=0;i<val.size()-1;i++){
            val[i+1].second=max(val[i+1].second,val[i].second);
        }
        int ans=0;
        for(int able:w){
            int l=0,r=val.size()-1,cur=0;
            while(l<=r){
                int mid=(l+r)/2;
                if(val[mid].first<=able){
                    l=mid+1;
                    cur=max(cur,val[mid].second);
                }else r=mid-1;
            }
            ans+=cur;
        }
        return ans;
    }
};