class DetectSquares {
public:
    unordered_map<vector<int>, int> ptsCount; 
    vector<vector<int>> points; 
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        ptsCount[point]++;     
        points.push_back(point); 
    }
    
    int count(vector<int> point) {
        int result = 0; 
        int px = point[0]; 
        int py = point[1]; 

        for(auto &ele: points) {
            int x = ele[0]; 
            int y = ele[1];
            if(abs(py - y) != abs(px - x) or x == px or y == py) {
                continue; 
            }

            result += ptsCount[{x, py}] * ptsCount[{px, y}];
        }
        return result; 
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */