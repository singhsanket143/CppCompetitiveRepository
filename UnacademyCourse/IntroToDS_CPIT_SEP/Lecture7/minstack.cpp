#include<bits/stdc++.h>
class MinStack {
public:
    std::stack<long long int> st;
    long long int min_;
    MinStack() {
        min_ = 1e15;
    }
    
    void push(int val) {
        if(st.size() == 0) {
            min_ = val;
            st.push(val);
        } else {
            if(val < min_) {
                st.push((long long int)((long long int)val - (long long int)min_));
                min_ = val;
            } else {
                st.push((long long int)((long long int)val - (long long int)min_));
            }
        }
        
    }
    
    void pop() {
        if(st.size() > 0) {
            if(st.top() >= 0) st.pop();
            else {
                min_ = (long long int)((long long int)min_ - (long long int)st.top());
                st.pop();
            }
        }
    }
    
    int top() {
        if(st.size() == 1) return st.top();
        if(st.top() >= 0) return (long long int)((long long int)min_+(long long int)st.top());
        else {
            return (int)min_;
        }
    }
    
    int getMin() {
        if(st.size() == 1) return st.top();
        return (int)min_;
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