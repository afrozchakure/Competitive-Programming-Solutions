// Refer @hiepit's solution in discuss tab
class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkInMap;  // contain the id, stationName and time;   // {stationName, t}
    unordered_map<string, pair<double,int>> routeMap;  // {totalCount, count}; 
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t}; 
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkIn = checkInMap[id];
        checkInMap.erase(id);  // removing the id from hashtable so that it doesn't make it big 
        
        string path = checkIn.first + "_" + stationName; 
        routeMap[path].first += t - checkIn.second; 
        routeMap[path].second += 1; 
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation + "_" + endStation; 
        auto& route = routeMap[routeName]; 
        return route.first / route.second; 
    }
};

// Time Complexity - O(1) 
// Space Complexity - O(N), since we're using hashmap

// Use two maps, one for keeping track of id, first stations and startTime and 
// the other for keeping track of path, totalTime and count 