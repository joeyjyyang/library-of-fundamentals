/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 32 ms - Beats 96.51% of submissions
 * Memory: 16.2 MB - Beats 6.99% of submissions
 * Data Structures: Stacks
 * Algorithms:
 * Other:
 */

class MinStack {
public:
    stack<int> all_stack;
    stack<int> min_stack;
    
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if (min_stack.empty() || x <= min_stack.top())
        {
            min_stack.push(x);
        }
        all_stack.push(x);
    }
    
    void pop() {
        if (all_stack.top() == min_stack.top())
        {
            min_stack.pop();
        }
        all_stack.pop();
    }
    
    int top() {
        return all_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
