class Solution {
public:
    bool isFileName(string file) {
        return file.find('.') != string::npos;
    }
    int lengthLongestPath(string input) {
        int ans = 0;
        stack<int> st;
        int pathLen = 0; 
        stringstream ss(input);
        string line;
        while (getline(ss, line, '\n')) {
            int depth = 0;
            while (depth < line.size() && line[depth] == '\t') {
                depth++;
            }
            string name = line.substr(depth);
            while (st.size() > depth) {
                pathLen -= st.top();
                st.pop();
            }
            int currentLen = name.size() + (st.empty() ? 0 : 1);
            if (isFileName(name)) {
                ans = max(ans, pathLen + currentLen);
            } else {
                st.push(currentLen);
                pathLen += currentLen;
            }
        }
        return ans;
    }
};
