class Solution {
public:
    int visited[205];
    void check(vector<int> v[],int itr)
    {
        if(visited[itr]) 
            return;
// Visiting all the connected nodes with our called node.
        visited[itr]=1;
        for(int i=0;i<v[itr].size();i++)
            check(v,v[itr][i]);

        return;
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0; // This is our count.
        vector<int> v[isConnected.size()];
// Structuring the Graph.
        for(int i=0;i<isConnected.size();i++)
            for(int j=0;j<isConnected[i].size();j++)
                if(isConnected[i][j])v[i].push_back(j);
// Calling the unvisited Nodes.
        for(int i=0;i<isConnected.size();i++)
            if(!visited[i])
            {
                check(v,i);
                ans++;
            }
        return ans;
    }
};