// https://leetcode.com/problems/min-stack/


class MinStack {
    stack<pair<int,int>> s;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(s.empty())
        {
            s.push({val,val});
            return;
        }
        s.push({val,min(val,s.top().second)});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
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