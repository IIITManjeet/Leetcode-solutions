class Solution {
public:
    set<string> ops = {"+", "-", "*", "/"};
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (auto t : tokens) {
            if (ops.find(t) == ops.end()) stack.push(stoi(t));
            else {
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                if (t == "+") stack.push(a + b);
                else if (t == "-") stack.push(a - b);
                else if (t == "*") stack.push(a * b);
                else stack.push(a / b);
            }
        }
        return stack.top();
    }
};