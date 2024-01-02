class Solution {
public:
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();

    vector<int> result;
    set<pair<int, int>, greater<pair<int,int>>> s;

    for(int i = 0; i < k; i++){
        s.insert(make_pair(nums[i], i));
    }

    auto i = s.begin();
    result.push_back(i->first);

    for(int i = 0, j = k; j < n; i++, j++){
        s.erase(make_pair(nums[i], i));
        s.insert(make_pair(nums[j], j));
        result.push_back(s.begin()->first);
    }

    return result;
}
};