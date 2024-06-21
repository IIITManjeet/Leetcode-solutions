class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int intial=0;
        int maxSatisf=0;
        int curWindow=0;
        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0)intial+=customers[i];
            else if(i<minutes)curWindow+=customers[i];
        }
        maxSatisf=curWindow;
        for(int i=minutes;i<customers.size();i++){
            curWindow+=customers[i]*grumpy[i];
            curWindow-=customers[i-minutes]*grumpy[i-minutes];
            maxSatisf=max(maxSatisf,curWindow);
        }
        return intial+maxSatisf;
    }
};