class Solution {
public:
    void reroot(int i, int parent, int n,vector<int>& sum,vector<int>& count,map<int,vector<int>>& gr){
        for (int j: gr[i]){
            if (j==parent) continue;
            sum[j]=sum[i]+n-2*count[j];
            reroot(j, i, n,sum,count,gr);
        }
    }
    void dfs(int node,vector<int>& sum,vector<int>& count,map<int,vector<int>>& gr,int parent=-1)
    {
        for(auto neigh:gr[node]){
            if(neigh==parent)continue;
            dfs(neigh,sum,count,gr,node);
            count[node]+=count[neigh];
            sum[node]+=sum[neigh]+count[neigh];
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        map<int,vector<int>>gr;
        for(auto e:edges){
            int u=e[0],v=e[1];
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        vector<int>sum(n,0),count(n,1);
        dfs(0,sum,count,gr);
        reroot(0, -1, n,sum,count,gr);
        return sum;
    }
};