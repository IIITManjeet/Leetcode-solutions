class Solution {
public:
    bool winnerOfGame(string colors) {
        int a=0,b=0;
        int n=colors.size();
        for(int i=1;i<n-1;i++){
            if(colors[i]==colors[i-1] && colors[i]==colors[i+1]){
                if(colors[i]=='A')a++;
                else b++;
            }
        }
        if(a>b)return true;
        return false;
    }
};