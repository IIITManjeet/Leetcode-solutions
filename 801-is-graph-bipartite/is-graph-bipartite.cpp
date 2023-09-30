class Solution {
private:
    bool check(int start,vector<vector<int>>& adj,int V,vector<int>& color){
        queue<int>q;
        color[start]=0;
        q.push(start);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(!check(i,adj,V,color)){
                return false;
                }
            }
        }
        return true;
    }
};