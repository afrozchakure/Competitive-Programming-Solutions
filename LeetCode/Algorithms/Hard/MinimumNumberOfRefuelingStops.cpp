// position, fuel
        // startFuel 
        // minimum number of 
// Greedy : "Keep reaching the farthest point, while filing the most gas"
// startfuel = 3 
// target = 15 

// 2, 5
// 3, 1 

// pq -> 5, 2 -> 1, 3

// pq.top() -> 5, 2 
// 3 +  5 = 8 

// pq -> 3, 6 -> 1, 3 
// pq.top() -> 3, 6 
// 8 + 3  => 11 

// pq.top() -> 1, 3
// pq.top() -> 1, 3, 
// 11 + 1 = 12 

// pq -> 6, 12 
// 12 + 6 = 18 

// 18 > 15 


// 6, 3 
// 12, 6

// store fuel in priority queue 


// Time Complexity - O(NLogN) 
// Space Complexity - O(N), since we are using a priority queue
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int xCurrent = startFuel; 
        int noOfStopsNeeded = 0; 

        // Max Heap on basis of fuel value
        priority_queue<int> pq; 

        for(auto &station: stations) {  // exhausted all your fuel
            int nextStationX = station[0]; 
            int fuelAtStation = station[1]; 

            while(xCurrent < nextStationX) {
                if(pq.isEmpty()) return -1; 

                int maxFuel = pq.top(); 
                pq.pop(); 

                xCurrent = xCurrent + maxFuel; 
                noOfStopsNeeded++; 
            }
            pq.push(fuelAtStation);
        }

        while(xCurrent < target) {
            if(pq.isEmpty()) {
                return -1; 
            } 

            int maxFuel = pq.top(); pq.pop();
            xCurrent += maxFuel; 
            noOfStopsNeeded++; 
        } 

        return noOfStopsNeeded;
    }
};

