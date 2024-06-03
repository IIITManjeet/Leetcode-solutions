class Solution {
public:
    int appendCharacters(string s, string t) {
        int n=s.size();
        int m=t.size();
        int spt=0,tpt=0;
        while(spt<n){
            if(s[spt]==t[tpt]){
                spt++;
                tpt++;
            }
            else spt++;
        }
        return m-tpt;
    }
};