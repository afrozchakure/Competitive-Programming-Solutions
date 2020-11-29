class FrontMiddleBackQueue {
public:
    int front = -1;
    int rear = -1;
    vector<int> q;
    
    
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        q.insert(q.begin(), val);
    }
    
    void pushMiddle(int val) {
        int middle;
        middle = q.size() / 2;
        q.insert(q.begin() + middle, val);
    }
    
    void pushBack(int val) {
        q.push_back(val);
    }
    
    int popFront() {
        if(q.size() == 0)
            return -1;
        int temp = q[0];
        q.erase(q.begin());
        // cout<<temp<<" ";
        return temp;
    }
    
    int popMiddle() {
        if(q.size() == 0)
            return -1;
        int middle;
        if(q.size() % 2 == 0)
            middle = (q.size() / 2) - 1;
        else
            middle = q.size() / 2;
        int temp = q[middle];
        q.erase(q.begin() + middle);
        return temp;
    }
    
    int popBack() {
        if(q.size() == 0)
            return -1;
        else{
            int temp = q.back();
            q.pop_back();
            return temp;
        }
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
 
 // Time Complexity of erase() and insert() function in not O(1)
 
 
