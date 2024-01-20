class Pair {
public:
    int element;
    int numMin;
    Pair(int el, int nm) : element(el), numMin(nm) {}
};

class Solution {
public:
    int mod = pow(10, 9) + 7;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int left[n], right[n];
        stack<Pair> st1, st2;

        // Fill left array;
        for (int i = 0; i < n; i++) {
            int curEle = arr[i];
            int cnt = 1;
            while (!st1.empty() && st1.top().element > curEle) {
                cnt += st1.top().numMin;
                st1.pop();
            }
            left[i] = cnt;
            st1.push({curEle, cnt});
        }

        // Reset count for the right array
        for (int i = n - 1; i >= 0; i--) {
            int curEle = arr[i];
            int cnt = 1;
            while (!st2.empty() && st2.top().element >= curEle) {
                cnt += st2.top().numMin;
                st2.pop();
            }
            right[i] = cnt;
            st2.push({curEle, cnt});
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            long long product = static_cast<long long>(left[i]) * right[i] * arr[i];
            sum += (product % mod);
            sum %= mod;
        }
        return sum;
    }
};
