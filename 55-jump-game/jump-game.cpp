class Solution {
public:
    bool canJump(vector<int>& v) {
        int maxPos=0;
        for(int i=0;i<v.size() && i<=maxPos;++i){
            maxPos=max(maxPos,v[i]+i);
        }
        return maxPos>=v.size()-1;
    }
};