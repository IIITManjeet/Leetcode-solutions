class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2)return n;
        int prev=1,cur=1;
        for(int i=2;i<=n;i++){
            int temp=cur;
            cur=temp+prev;
            prev=temp;
        }return cur;
    }
};