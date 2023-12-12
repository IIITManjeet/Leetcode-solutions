typedef long long ll;
class Solution {
public:
    int mod=1e9+7;
    int nthMagicalNumber(int n, int a, int b) {
        ll ans=0,l=min(a,b),r=n*1LL*min(a,b);
        int lcm=(a*b)/__gcd(a,b);
        while(l<=r){
            ll mid=(l+(r-l)/2);
            ll position_check_inclusion_exclusion=mid/b+mid/a-mid/lcm;
            if(position_check_inclusion_exclusion<n)l=mid+1;
            else{
                ans=mid%mod;
                r=mid-1;
            }
        }
        return ans;
    }
};