class MinStack {
    stack<int> min_st, st;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);
        if (min_st.empty())
            min_st.push(val);
        else {
            if (min_st.top() >= val)
                min_st.push(val);
        }
    }

    void pop()
    {
        if (st.top() == min_st.top())
            st.pop(), min_st.pop();
        else
            st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return min_st.top();
    }
};
