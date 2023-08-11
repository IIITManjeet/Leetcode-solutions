class Solution {
public:
    double binary(double x,long long n){
        if(n==0)return 1;
        if(n<0){
            return 1.0/binary(x,-1*n);
        }
        if(n&1){
            return x*binary(x*x,(n-1)/2);
        }
        else{
            return binary(x*x,n/2);
        }
    }
    double myPow(double x, int n) {
        return binary(x,(long long)n);
    }
};