class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end());
        int n=inter.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int start=inter[i][0],end=inter[i][1];
            if (!ans.empty() && end <= ans.back()[1])continue;
            for(int j=i+1;j<n;j++){
                if(end>=inter[j][0]){
                    end=max(end,inter[j][1]);
                }else break;
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};