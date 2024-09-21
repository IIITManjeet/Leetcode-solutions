class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>st;
        for(int i=1;i<=n;i++){
            st.push_back(to_string(i));
        }
        sort(st.begin(),st.end());
        vector<int>ans;
        for(auto el:st){
            ans.push_back(stoi(el));
        }
        return ans;
    }
};