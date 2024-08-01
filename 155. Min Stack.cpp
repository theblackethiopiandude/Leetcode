class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        minSt.push((minSt.empty())? val: min(val, minSt.top()));   
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
private:
    stack<int> st;
    stack<int> minSt;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
