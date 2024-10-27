class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        int level = 0;  

        unordered_map<int, vector<int>> m;   // store - bus stop no. -> bus numbers list 

        for(int i=0; i<n; i++) {
            for(int j=0; j<routes[i].size(); j++) {
                int busStopNo = routes[i][j]; 
                int busNo = i; 
                m[busStopNo].push_back(busNo);
            }
        }

        // bfs 
        queue<int> queue;
        unordered_set<int> busStopVisited; 
        unordered_set<int> busVisited;  

        queue.push(source);
        busStopVisited.insert(source); 

        while(!queue.empty()) {
            int size = queue.size(); 
            while(size--) {
                int rem = queue.front(); 
                queue.pop(); 

                if(rem == target) {
                    return level; 
                }

                vector<int> buses = m[rem]; 
                for(int bus: buses) {
                    if(busVisited.find(bus) != busVisited.end()) {
                        continue; 
                    }

                    vector<int> arr = routes[bus]; 

                    for(int busStop: arr) {
                        if(busStopVisited.find(busStop) != busStopVisited.end()) {
                            continue; 
                        } 

                        queue.push(busStop); 
                        busStopVisited.insert(busStop); 
                    }
                    busVisited.insert(bus); 
                }
            }
            level += 1; 
        }

        return -1; 

    }
};

// Time Complexity - O(N) 
// Space Complexity - O(N), since we're using a map to keep track of bus and busStop