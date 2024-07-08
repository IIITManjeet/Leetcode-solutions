#include <set>

class Solution {
public:
    int findTheWinner(int n, int k) {
        std::set<int> st;
        for (int i = 1; i <= n; ++i) st.insert(i);
        auto it = st.begin();
        while (st.size() > 1) {
            for (int count = 1; count < k; ++count) {
                ++it;
                if (it == st.end()) it = st.begin();
            }
            auto toRemove = it++;
            if (it == st.end()) it = st.begin();
            st.erase(toRemove);
        }
        
        return *st.begin();
    }
};
