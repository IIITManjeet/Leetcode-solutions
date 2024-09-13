class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& query) {
        int n=a.size(),q=query.size();
        vector<int>pre(n);
        pre[0]=a[0];
        for(int i=1;i<n;i++){
            pre[i]=a[i]^pre[i-1];
        }
        vector<int>ans;
        for(int i=0;i<q;i++){
            int l=query[i][0];
            int r=query[i][1];
            int val = l == 0 ? pre[r] : pre[r] ^ pre[l - 1];
            ans.push_back(val);
        }
        return ans;
    }
};