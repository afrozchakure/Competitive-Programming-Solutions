// AAABBCC n = 1 

// A - 3 
// B - 2 
// C - 2 

// start with most frequent characters which is A in this case 

// MaxHeap logN -> log26

// Time Complexity - O(N)
// Space Complexity - O(N)

// Queue

// - Time Complexity - O(M)
// - Space Complexity - O(M * 100), M is the number of elements in tasks array
// - Refer solution by Neetcode : https://www.youtube.com/watch?v=s8p8ukTyA2I
// - Nick White's video can be a bit confusing for this one: https://www.youtube.com/watch?v=eGf-26OTI-A

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> char_map(26); 
        for(int i=0; i<tasks.size(); i++) {
            char_map[tasks[i] - 'A']++; 
        }
        
        // count of character
        priority_queue<int> pq; 
        for(int i=0; i<char_map.size(); i++) {
            if(char_map[i] > 0) {
                pq.push(char_map[i]); 
            }
        }
        
        // count, idleTime 
        queue<pair<int, int> > q; 
        int time = 0; 
        while(!pq.empty() || !q.empty()) {
            time++; 
            if(!pq.empty()) {
                int count = pq.top() - 1; 
                pq.pop(); 
                if(count > 0) {
                    q.push(make_pair(count, n + time)); 
                }
            }
            // cout<<time<<" ";
            if(!q.empty() && q.front().second == time) {
                // cout<<q.front().first<<" "; 
                pq.push(q.front().first); 
                q.pop(); 
            }
        }
        
        return time; 
    }
};
