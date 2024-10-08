class KthLargest {
public:
    int n;
     priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        n=k;
        for(auto i:nums){
            if(pq.size()<k){
                pq.push(i);
                continue;
            }
            if(i>pq.top()){
                pq.pop();
                pq.push(i);
            }
        }
    }
    
    int add(int val) {
       if(pq.size()<n){
                pq.push(val);
                return pq.top();
            }
            if(val>pq.top()){
                pq.pop();
                pq.push(val);
            }
            return pq.top();
    }
};