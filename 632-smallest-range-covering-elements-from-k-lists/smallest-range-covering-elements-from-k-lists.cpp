class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int>res={-100000,100000};
        int k=nums.size();
        int maxVal=INT_MIN;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<k;i++){
            int mol=nums[i][0];
            vector<int>v={mol,0,i};
            maxVal=max(maxVal,mol);
            pq.push(v);
        }
        while(true){
            vector<int>v=pq.top();
            pq.pop();
            if(res[1]-res[0]>maxVal-v[0]){
                res[0]=v[0],res[1]=maxVal;
            }
            v[1]++;
            vector<int>cl=nums[v[2]];
            if(v[1]==cl.size())break;
            else{
                v[0]=cl[v[1]];
                maxVal=max(maxVal,cl[v[1]]);
                pq.push(v);
            }
        }
        return res;
    }
};