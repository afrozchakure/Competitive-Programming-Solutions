class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size() == 1) {
            return 0; 
    }

        int n = graph.size(); 
        int finalState = pow(2, n) - 1;

        // {i, BitState}
        queue<pair<int, int>> q; 

        // adding all nodes initially because we can start anywhere 
        for(int i=0; i<graph.size(); i++) {
            q.push(make_pair(i, 1 << i)); // push bit converted values, bitstate 
        }

        vector<vector<int>> visitedMap(n, vector<int>(finalState + 1)); 

        int shortestPath = 0; 
        while(!q.empty()) {
            int size = q.size();
            shortestPath++; 
            for(int i=0; i<size; i++) {
                pair<int, int> head = q.front(); 
                q.pop(); 
                int nodeId = head.first; 
                int visitedNodeBitState = head.second; 
                for(int neighbor: graph[nodeId]) {
                    int newVisitedNodeBitState = visitedNodeBitState | (1 << neighbor);

                    // If the same node was visited again with same bit, it means this node 
                    // can be skipped, For example: 1->0->1->0, First 1 we have {1, 10}, then we have {0, 11}, then we will 
                    // have {1, 11}. Lastly, we have {0, 11} which is a state we already had before. So we don't visit this again 

                    if(visitedMap[neighbor][newVisitedNodeBitState] == 1) 
                        continue;
                    visitedMap[neighbor][newVisitedNodeBitState] = 1; 
                    if(newVisitedNodeBitState == finalState) {
                        return shortestPath;
                    } 
                    q.add(make_pair(neighbor, newVisitedNodeBitState));
                }
            }
        }
        return -1; 

    }
};

// Notes: 
// 1. You have to start BFS starting form all states 
// 2. Basic BFS with visited node will not work 
// 3. Avoid indefinite loops 

// Repetition is allowed: You can visit a node again and again

