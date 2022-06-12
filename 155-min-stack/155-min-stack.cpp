class MinStack {
public:
    stack<int> s;
    stack<int> mnStack;
    
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(mnStack.empty()){
            mnStack.push(val);
        }
        else if(mnStack.top() >= val){
            mnStack.push(val);
        }
    }
    
    void pop() {
        if(mnStack.top() == s.top()){
            mnStack.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mnStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */