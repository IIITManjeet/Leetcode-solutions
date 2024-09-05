class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dis(n+1,INT_MAX);
        vector<vector<pair<int,int>>>adj(n+1);
        int m=times.size();
        for(int i=0;i<m;i++){
            adj[times[i][0]].push_back(make_pair(times[i][1],times[i][2]));
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push(make_pair(0,k));
        dis[k]=0;
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            for(auto x:adj[u]){
                int a=x.first;
                int w=x.second;
                if(dis[a]>(dis[u]+w)){
                    dis[a]=dis[u]+w;
                    pq.push(make_pair(dis[a],a));
                }

            }
        }
        int ans=INT_MIN;
            for(int i=1;i<=n;i++){
                if(dis[i]==INT_MAX)return -1;
                if(dis[i]!=INT_MAX){
                ans=max(ans,dis[i]);
                }
            }
            if(ans==INT_MAX||ans==0){
                return -1;
            }
        return ans;
    }
};