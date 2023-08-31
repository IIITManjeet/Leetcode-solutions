class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>maxReach(n+1,0);
        for(int i=0;i<ranges.size();i++){
            int start=max(0,i-ranges[i]);
            int end=min(n,i+ranges[i]);
            maxReach[start]=max(maxReach[start],end);
        }
        int taps=0,curr_end=0,next_end=0;
        for(int i=0;i<=n;i++){
            if(i>next_end)return -1;
            if(i>curr_end){
                taps++;
                curr_end=next_end;
            }
            next_end=max(next_end,maxReach[i]);
        }
        return taps;
    }
};