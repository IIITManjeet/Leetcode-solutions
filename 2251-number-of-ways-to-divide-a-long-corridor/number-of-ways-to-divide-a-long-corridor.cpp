class Solution {
public:
    int mod =1000000007;     
    int numberOfWays(string corridor) {
    long long m=corridor.length(),count=1;
    vector<int> seats; //stores indices of all seats
    for (int i = 0; i < m; i++) { 
        if (corridor[i] == 'S') {
            seats.push_back(i);
        }
    }
    int n = seats.size();

    if (n==0 || n%2!=0) {
        return 0;
    }

//seats[i]-seats[i-1] will give us number of Ps between each pair of S
    for (int i = 2; i < n; i += 2) {
        count = (count * (seats[i]- seats[i - 1]))%mod;
    }

    return count;
    
    }
};