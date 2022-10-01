class Solution {
public:

    struct comp {
        bool operator() (const pair &x, const pair &y) const {
            if(x.second == y.second) {
                return x.second > y.second; 
            } 
            return x.first > y.second; 
        }
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        // lefti (x-coordinate of left edge) , righti (x coordinate of right edge), heighti 
            
        // (leftix, h) -> (rightix, h) 
        vector<vector<int>> result; 
        vector<pair<int, int>> heights; 

        transformBuilding(buildings, heights); 
        sort(heights.begin(), heights.end(), mycomp); 

        priority_queue<int> pq; 
        pq.push(0); 
        int preMax = 0; 
        for(int &height: heights) {
            if(height[1] < 0) {
                pq.push(-height[1]); 
            } else {
                pq.pop(); 
            }
            int currMax = pq.top(); 
            if(currMax != preMax) {
                vector<int> subRes; 
                subRes.push_back(height[0]); 
                subRes.push_back(currMax); 
                result.push_back(subRes); 
                preMax = currMax; 
            }
        }
        return result; 
    }
    void transformBuilding(vector<vector<int>> &sbuildings, vector<pair<int, int>> &heights) {
        for(auto &building: buildings) {
            heights.push_back(make_pair(building[0], -building[2])); 
            heights.push_back(make_pair(building[1], building[2])); 
        }
    }
};

// ===================================================================

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> skyline; 

        map<int, vector<pair<int, int>>> map;  // key: pos, value: vector of <height, start| end> pairs 
        for(auto &building: buildings) {
            map[building[0]].push_back({building[2], 0}); // add startpoint 
            map[building[1]].push_back({building[2], 1}); // add endpoint 
        }

        multiset<int> q; 

        for(auto& [pos, heights] : map) {   // heights[height, start|end]
            for(auto& [height, type]: heights) {  // height and type 
                if(type == 0) q.insert(height); 
                else q.erase(q.find(height));  // erase the positive value of height 
            }

            int newHeight = q.empty() ? 0 : *q.rbegin(); 
            if(!skyline.empty() && skyline.back()[1] == newHeight) continue; 
            else skyline.push_back(vector<int>({pos, newHeight})); 
        }
        return skyline; 
        
    }
};