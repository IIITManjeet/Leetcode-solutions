class Solution {
public:
    int sum(int num){
        int ans=0;
        while(num){
            ans+=num%10;
            num/=10;
        }
        return ans;
    }
    int addDigits(int num) {
        int s=sum(num);
        if(s<10)return s;
        else return addDigits(s);
    }
};