class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& mt) {
        sort(mt.begin(), mt.end());
        int m = mt.size();
        vector<int> room(n, 0);
        priority_queue<int, vector<int>, greater<int>> avail;
        // room available index
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        // busy-(endtime,index)
        for (int i = 0; i < n; i++) avail.push(i);
        for (auto meet : mt) {
            int start = meet[0], end = meet[1]; // Corrected variable names
            // agar end time kisi room ke start se pehle hua toh room khali hi hoga.
            while (busy.size() > 0 && busy.top().first <= start) { // Corrected the condition from "s" to "start"
                avail.push(busy.top().second);
                busy.pop();
            }
            // assigning rooms if empty
            if (avail.size() > 0) {
                int first = avail.top();
                room[first]++;
                avail.pop();
                busy.push({(long long)end, first}); // Cast end to long long to prevent overflow
                continue;
            }
            // if no rooms empty
            // we'll use the first over meeting
            auto first = busy.top();
            long long availTime = first.first, r = first.second;
            busy.pop();
            room[r]++;
            busy.push({availTime + end - start, r}); // Corrected end time calculation
        }
        return max_element(room.begin(), room.end())-room.begin();
    }
};
