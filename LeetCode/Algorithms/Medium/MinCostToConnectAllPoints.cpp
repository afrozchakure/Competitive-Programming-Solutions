#include<iostream> 
using namespace std; 

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(); res = 0;
        vector<bool> visited(n); 
        priority_queue<pair<int, int>> pq;  // {cost, node} -> here we create a minheap using a max heap by pushing -negative values into the maxHeap

        int connected = 0; 
        while(connected++ <= n-2) {  // we do this n-2 times (since j will be one greater than i's value)
            visited[i] = true; 
            for(int j=0; j<n; j++) {
                if(!visited[j]) {
                    pq.push({-(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])), j});  // creating a min heap 
                }
            }
            while(visited[pq.top().second]) {
                pq.pop(); 
            }
            res += pq.top().first; 
            i = pq.top().second; 
            pq.pop(); 
        }
        return res; 
    }
};


int main() {
    return 0; 
}

// Time complexity - O((V+E))log(V)), since insertion in priority queue takes logarithmic time 
// Space Complexity - O(N) 