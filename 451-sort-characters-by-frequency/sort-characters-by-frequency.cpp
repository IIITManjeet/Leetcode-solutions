class Solution {
public:
    string frequencySort(string s) {
         auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second;
        };
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        map<char,int>mp;
        for(auto ch:s){
            mp[ch]++;
        }
        for(auto it:mp){
            pq.push({it.first,it.second});
        }
        string ans="";
        while(!pq.empty()){
            char ch=pq.top().first;
            int cnt=pq.top().second;
            for(int i=0;i<cnt;i++){
                ans+=ch;
            }
            pq.pop();
        }
        return ans;
    }
};