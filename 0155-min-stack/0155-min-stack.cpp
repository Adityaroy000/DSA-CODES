class MinStack {
    stack<int> s1; 
    int min;

public:
    MinStack() {
        min = INT_MAX;
    }

    void push(int val) {
        if (val <= min) {
            s1.push(min);
            min = val;
        }
        s1.push(val);
    }

    void pop() {
        if (s1.top() == min) {
            s1.pop();     
            min = s1.top(); 
        }
        s1.pop();
    }

    int top() {
        return s1.top();  
    }

    int getMin() {
        return min;  
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