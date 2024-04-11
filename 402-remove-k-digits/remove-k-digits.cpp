class Solution {
public:
    string removeKdigits(string num, int k) {
        string s="";
        int n=num.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                k--;
                st.pop();
            }
            st.push(num[i]);
        }
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        int pos = s.find_first_not_of('0');
        s = (pos == std::string::npos) ? "0" : s.substr(pos);
        return s;
    }
};