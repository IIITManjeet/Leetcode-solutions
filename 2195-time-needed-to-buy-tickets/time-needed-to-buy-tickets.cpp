class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        int n=tickets.size();
        for(int i=0;i<n;i++){
            q.push(i);
        }
        int ans=0;
        while(!q.empty()){
            int val=q.front();
            ans++;
            tickets[val]--;
            q.pop();
            if(val==k && tickets[k]==0)return ans;
            if(tickets[val]!=0)q.push(val);
        }
        return ans;
    }
};