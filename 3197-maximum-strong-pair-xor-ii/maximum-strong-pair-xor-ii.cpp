class Solution {
public:
    struct xorTrie {
    xorTrie *p[2] = {};
    void insert(int n, int l = 19) {
        xorTrie *r = this;
        for (; l >= 0; --l) {
            int bit = (n & (1 << l)) > 0;
            if (r->p[bit] == nullptr)
                r->p[bit] = new xorTrie();
            r = r->p[bit];
        }
    }
    bool remove(int n, int l = 19) {
        if (l < 0)
            return true;
        int bit = (n & (1 << l)) > 0;
        if (p[bit] != nullptr && p[bit]->remove(n, l - 1)) {
            delete p[bit];
            p[bit] = nullptr;
        }
        return p[0] == nullptr && p[1] == 0;
    }    
    int maxXor(int n, int l = 19) {
        if (l < 0)
            return 0;
        int bit = (n & (1 << l)) > 0;
        if (p[!bit] != nullptr)
            return (1 << l) + p[!bit]->maxXor(n, l - 1);
        return p[bit]->maxXor(n, l - 1);
    }  
};
int maximumStrongPairXor(vector<int>& nums) {
    xorTrie t;
    sort(begin(nums), end(nums));
    int i = 0, j = 0, res = 0; 
    for (int i = 0; i < nums.size(); ++i) {
        t.insert(nums[i]);
        while (nums[j] * 2 < nums[i])
            t.remove(nums[j++]);
        res = max(res, t.maxXor(nums[i]));
    }
    return res;
}
};