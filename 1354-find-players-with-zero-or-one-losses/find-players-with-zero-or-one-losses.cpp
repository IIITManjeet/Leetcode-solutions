class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>lost_map;
        for(int i=0;i<matches.size();i++){
            lost_map[matches[i][1]]++;
        }
        vector<int>noLost,oneLost;
        for(int i=0;i<matches.size();i++){
            int win=matches[i][0],loss=matches[i][1];
            if(lost_map.find(win)==lost_map.end()){
                noLost.push_back(win);
                lost_map[win]=2;
            }
            if(lost_map[loss]==1)oneLost.push_back(loss);
        }
        sort(noLost.begin(),noLost.end());
        sort(oneLost.begin(),oneLost.end());
        return {noLost,oneLost};
    }
};