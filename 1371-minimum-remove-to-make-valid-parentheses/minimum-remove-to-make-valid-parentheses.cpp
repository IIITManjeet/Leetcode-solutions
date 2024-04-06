class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch==')' || ch=='('){
                if(st.empty())st.push({ch,i});
            else if(st.top().first=='(' && ch==')')st.pop();
            else st.push({ch,i});
            }
        }
        set<int>ind;
        while(!st.empty()){
           ind.insert(st.top().second);
           st.pop();
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(ind.find(i)==ind.end()){
                ans+=s[i];
            }
        }
        return ans;
    }
};