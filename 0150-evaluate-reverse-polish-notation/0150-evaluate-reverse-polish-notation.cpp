class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto &t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                int res;
                if (t == "+") res = a + b;
                else if (t == "-") res = a - b;
                else if (t == "*") res = a * b;
                else res = a / b;
                stk.push(res);
            }             
            else {
                stk.push(stoi(t));
            }
        }
        return stk.top();
    }
};
