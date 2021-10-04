class MinStack
{
public:
    /** initialize your data structure here. */
    vector<int> stack;

    MinStack()
    {
    }

    void push(int x)
    {
        stack.push_back(x);
    }

    void pop()
    {
        int front = stack.front();
        stack.pop_back();
    }

    int top()
    {
        int front = stack.back();
        return front;
    }

    int getMin()
    {
        return *min_element(stack.begin(), stack.end());
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

// Time Complexity :
// push() - O(1)
// pop() - O(1)
// top() - O(1)
// getMin() - O(N)

// Space Complexity : O(N)