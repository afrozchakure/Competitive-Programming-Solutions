// Refer @tianyu's solution to the problem 

class NestedIterator {
private:
    stack<NestedInteger> nodes;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int size = nestedList.size();
        for(int i = size - 1; i >= 0; --i) {
            nodes.push(nestedList[i]);
        }
    }

int next() {
    int result = nodes.top().getInteger();
    nodes.pop();
    return result;
}

bool hasNext() {
    while(!nodes.empty()) {
        NestedInteger curr = nodes.top();
        if(curr.isInteger()) {
            return true;
        }
        
        nodes.pop();
        vector<NestedInteger>& adjs = curr.getList();
        int size = adjs.size();
        for(int i = size - 1; i >= 0; --i) {
            nodes.push(adjs[i]);
        }
    }
    
    return false;
    }
};
