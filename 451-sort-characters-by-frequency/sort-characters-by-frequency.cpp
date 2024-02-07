class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(256, 0); // Assuming ASCII characters
        
        for (char ch : s) {
            freq[ch]++;
        }
        
        auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        
        for (int i = 0; i < 256; ++i) { // Assuming ASCII characters
            if (freq[i] > 0) {
                pq.push({static_cast<char>(i), freq[i]});
            }
        }
        
        string ans = "";
        while (!pq.empty()) {
            char ch = pq.top().first;
            int cnt = pq.top().second;
            ans.append(cnt, ch);
            pq.pop();
        }
        
        return ans;
    }
};
