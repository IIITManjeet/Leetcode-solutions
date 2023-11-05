class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int answer = INT_MAX;
        for(int i = 0;i + k <= blocks.length();i ++) {
            int temp=0;
            string x = blocks.substr(i, k);
            for(int i=0;i<x.size();i++){
                if(x[i]=='W')temp++;
            }
            answer=min(temp,answer);
        }
        return answer;
    }
};