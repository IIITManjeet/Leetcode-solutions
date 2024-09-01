class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        int a=c1[0]-'0',b=c1[1]-'a',c=c2[0]-'0',d=c2[1]-'a';
        return (a+b)%2==(c+d)%2;
    }
};