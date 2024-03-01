class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1')ones++;
        }
        string S="";
        int i=0;
        for(;i<ones-1;i++){
            S+='1';
        }
        for(;i<n-1;i++)S+='0';
        S+='1';
        return S;
    }
};