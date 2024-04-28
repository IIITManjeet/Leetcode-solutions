#define all(v) v.begin(), v.end()
class Solution {
public:
    int minimumAddedInteger(vector<int>& n1, vector<int>& n2) {
    sort(all(n1));
    sort(all(n2));
    int res = INT_MAX;
    for (int i = 0; i < 3; ++i) {
        int skip = i;
        for (int j = i + 1; skip < 3 && j - skip < n2.size(); ++j)
            skip += n2[j - skip] - n1[j] != n2[0] - n1[i];
        if (skip < 3)
            res = min(res, n2[0] - n1[i]);
    }
    return res;
}
};
