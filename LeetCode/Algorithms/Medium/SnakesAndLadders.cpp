class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int length = board.size(); 

        queue<pair<int, int>> q; // [square, moves]
        q.push(make_pair(1, 0)); 
        unordered_set<int> visit; 
        while(!q.empty()) {
            int square, moves; 
            square, moves = visit.front(); 
            visit.pop(); 

            
        }


    }
};