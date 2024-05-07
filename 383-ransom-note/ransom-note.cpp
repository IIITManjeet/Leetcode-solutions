class Solution {
public:
    bool canConstruct(string r, string m) {
        map<char,int>mp;
        for(auto it:r)mp[it]++;
        for(auto it:m){
            if(mp.find(it)!=mp.end()){
                if(--mp[it]==0)mp.erase(it);
            }
        }
        return mp.empty();
    }
};