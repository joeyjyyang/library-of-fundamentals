/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: 0 ms - Beats 100.0% of submissions
 * Memory: 7.2 MB - Beats 10.84% of submissions
 */

class MyStack {
public:
    queue<int> queue1;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue1.push(x);
	int num_rotations = queue1.size() - 1;
	// Rotate queue until new element x is at front.
        for (int i = 0; i < num_rotations; i++)
        {
            queue1.push(queue1.front());
            queue1.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = queue1.front();
        queue1.pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return queue1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return queue1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
