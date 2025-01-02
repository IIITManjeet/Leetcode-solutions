class Solution {
public:
    void getarray(long long num, vector<long long>& v) {
        while (num > 0) {
            if (num == 1) {
                v[0]++;
                return;
            }
            if (num == 2) {
                v[0]++;
                v[1]++;
                return;
            }

            int bitlength = log2(num) + 1;
            long long nearest2 = (1LL << (bitlength - 1));
            for (int i = bitlength - 2; i >= 0; i--) {
                v[i] += (nearest2 / 2);
            }

            long long afterpower2 = num - nearest2 + 1;
            v[bitlength - 1] += afterpower2;
            num = afterpower2 - 1;
        }
    }

    vector<long long> solve(long long num) {
        vector<long long> v(31, 0);
        getarray(num, v);
        return v;
    }

    int rangeBitwiseAnd(int left, int right) {
        vector<long long> leftarray = solve(left - 1); 
        vector<long long> rightarray = solve(right); 

        vector<long long> finalarray(31, 0);
        for (int i = 0; i < 31; i++) {
            finalarray[i] = rightarray[i] - leftarray[i];
        }

        long long res = 0;
        long long diffbits = right*1ll - left*1ll + 1ll;
        for (int i = 0; i < 31; i++) {
            if (finalarray[i] == diffbits) {
                res |= (1LL << i);
            }
        }

        return res;
    }
};
