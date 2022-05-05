// Time Complexity - Peek - O(N) 
// Space Complexity - O(N), since we're using two stacks
class MyQueue {
public:
    stack<int> input, output; 
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x); 
    }
    
    int pop() {
        int n= peek(); 
        output.pop(); 
        return n; 
    }
    
    int peek() {
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top()); input.pop(); 
            }
        }
        
        return output.top(); 
    }
    
    bool empty() {
        return input.empty() && output.empty(); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
