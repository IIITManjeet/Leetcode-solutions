class Solution {
public:
    int minBitFlips(int start, int goal) {
       int ans=0;
        string s= bitset<32> (start).to_string();
        string str= bitset<32> (goal).to_string();
        for(int i=0;i<32;i++){
            if(s[i]!=str[i]) ans++;
        }
        return ans;
    }
};