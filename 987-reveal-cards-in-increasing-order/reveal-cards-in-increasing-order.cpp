#define all(v) v.begin(), v.end()
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        sort(all(deck),greater<int>());
        deque<int>dq;
        dq.push_front(deck[0]);
        for(int i=1;i<n;i++){
            if(dq.size()==1)dq.push_front(deck[i]);
            else{
                int val=dq.back();
                dq.pop_back();
                dq.push_front(val);
                dq.push_front(deck[i]);
            }
        }
        vector<int>ans;
        while(!dq.empty()){
            ans.push_back(dq.front());
            dq.pop_front();
        }
        return ans;
    }
};