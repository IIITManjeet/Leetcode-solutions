#define all(v) v.begin(), v.end()
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<char, char> nextSlot = {
            {'0', '1'}, {'1', '2'}, {'2', '3'}, {'3', '4'}, {'4', '5'},
            {'5', '6'}, {'6', '7'}, {'7', '8'}, {'8', '9'}, {'9', '0'}
        };
        unordered_map<char, char> prevSlot = {
            {'0', '9'}, {'1', '0'}, {'2', '1'}, {'3', '2'}, {'4', '3'},
            {'5', '4'}, {'6', '5'}, {'7', '6'}, {'8', '7'}, {'9', '8'}
        };
        unordered_set<string> vis(deadends.begin(), deadends.end());

        // Check if the initial state is a deadend
        if(vis.find("0000") != vis.end()) {
            return -1;
        }

        queue<string> q;
        q.push("0000");
        vis.insert("0000");
        int ans = 0;

        while(!q.empty()) {
            int levelSize = q.size(); // Number of elements at the current level
            for(int c = 0; c < levelSize; c++) {
                string s = q.front();
                q.pop();

                if(s == target) {
                    return ans;
                }

                for(int i = 0; i < 4; i++) {
                    string next = s; // Create a copy of s to modify
                    next[i] = nextSlot[next[i]]; // Correct: use the mapped character
                    if(vis.find(next) == vis.end()) {
                        vis.insert(next);
                        q.push(next);
                    }

                    string prev = s; // Create another copy of s to modify
                    prev[i] = prevSlot[prev[i]]; // Correct: use the mapped character
                    if(vis.find(prev) == vis.end()) {
                        vis.insert(prev);
                        q.push(prev);
                    }
                }
            }
            ans++; // Increment the number of moves after processing this level
        }

        return -1;
    }
};