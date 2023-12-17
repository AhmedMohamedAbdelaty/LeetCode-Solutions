class Solution {
    bool notDigit(string& s)
    {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
    int calc(int a, int b, string& op)
    {
        if (op == "+")
            return a + b;
        else if (op == "-")
            return a - b;
        else if (op == "*")
            return a * b;
        else
            return a / b;
    }

public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < tokens.size(); i++) {
            if (notDigit(tokens[i])) {
                pair<int, int> p;
                p.second = st.top();
                st.pop();
                p.first = st.top();
                st.pop();
                ans = calc(p.first, p.second, tokens[i]);
                st.push(ans);
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};