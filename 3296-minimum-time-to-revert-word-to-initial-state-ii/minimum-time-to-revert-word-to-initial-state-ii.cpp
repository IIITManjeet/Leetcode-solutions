#include <string_view>

class Solution {
public:
    int minimumTimeToInitialState(std::string_view word, int k) {
        int n = word.size();
        int count = 1;
        for (int i = 0; i < n - k; i += k) {
            std::string_view pre = word.substr(i+k, n - (i + k));
            std::string_view suf = word.substr(0, n - (i + k));
            if (pre == suf)
                return count;
            else
                count++;
        }
        return count;
    }
};
