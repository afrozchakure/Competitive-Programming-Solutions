class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // 4 - 10 slots (0 to 9)
        if(deadends.find("0000") != deadends.end()) {
            return -1; 
        }

        deque<pair<string, int>> q;
        q.push(make_pair("0000", 0));

        unordered_set<int> visited(deadends.begin(), deadends.end()); 

        while(!q.empty()) {
            auto &lockTurns = q.back(); 
            q.pop_left(); 

            string lock = lockTurns[0]; 
            int turns = lockTruns[1]; 

            if(lock == target) {
                return turns;
            }

            vector<int> result = children(lock);

            for(auto &child: result) {
                if(visited.find(child) == visited.end()) {
                    visited.insert(child); 
                    q.push(make_pair(child, turns + 1)); 
                } 
            }
        }
        return -1; 
    }

    vector<string> children(string lock) {
        vector<string> result; 

        for(int i=0; i<4; i++) {
            string digit = t_string(((lock[i] - '9') + 1) % 10);
            
            lock[i] = digit; 
            result.push_back(lock);
            string digit = t_string(((lock[i] - '9') - 1 + 10) % 10);
            
            lock[i] = digit; 
            result.push_back(digit); 
        }

        return result;
    }
};