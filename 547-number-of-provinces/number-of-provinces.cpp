class Solution {
public:
    void dfs(int i,int num,vector<vector<int>>& isConnected,vector<bool>&visited){
        visited[i]=true;
        vector<int>adj;
        for(int j=0;j<num;j++){
            int x=isConnected[i][j];
            if(x==1){
                adj.push_back(j);
            }
        }
        for(auto x:adj){
            if(!visited[x]){
                dfs(x,num,isConnected,visited);
            }
        }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int num=isConnected.size();
        vector<bool>visited(num,false);int count=0;
        for(int i=0;i<num;i++){
            if(!visited[i]){
                count++;
                dfs(i,num,isConnected,visited);
            }
        }
        return count;
    }
};