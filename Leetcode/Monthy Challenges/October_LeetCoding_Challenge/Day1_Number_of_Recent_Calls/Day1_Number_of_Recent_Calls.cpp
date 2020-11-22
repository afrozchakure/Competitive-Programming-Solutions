#include<queue>

class RecentCounter {
public:
    queue <int> q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while(q.front() < t - 3000) // If q.front() is beyond lower limit -> pop it out
        {
            q.pop();
        }
        return q.size();
        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
