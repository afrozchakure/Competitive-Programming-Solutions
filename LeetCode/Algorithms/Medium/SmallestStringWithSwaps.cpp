// - Time Complexity - O(E + VlogV) 
// - Space Complexity - O(E + V)
// - Watch Vishal Rajput's solution to the problem and leetcode solution 
// solution: 
// 1. Build graph 
// 2. DFS (all connected component) 
// 3. Sort chars & indices array 
// 4. Place ith char at ith index 

class Solution {
public:
    static const int N = 100001; 
    vector<int> adj[N]; 
    bool visited[N]; 
    
    void DFS(string &s, int vertex, vector<char>& characters, vector<int> &indices) {
        characters.push_back(s[vertex]); 
        indices.push_back(vertex); 
        
        visited[vertex] = true; 
        
        // Traverse the adjacents 
        for(int adjacent: adj[vertex]) {
            if(!visited[adjacent]) {
                DFS(s, adjacent, characters, indices); 
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
          // building the adjacency list 
        for(vector<int> edge: pairs) {
            int source = edge[0]; 
            int destination = edge[1]; 
            
            // undirected edge 
            adj[source].push_back(destination); 
            adj[destination].push_back(source); 
        }
        
        for(int vertex = 0; vertex < s.size(); vertex++) {
            // If not coverted in the DFS yet 
            if(!visited[vertex]) {
                vector<char> characters; 
                vector<int> indices; 
                
                DFS(s, vertex, characters, indices); 
                // Sort the list of characters and indices 
                sort(characters.begin(), characters.end()); 
                sort(indices.begin(), indices.end()); 
                
                // Store the sorted characters corresponding to teh index 
                for(int index = 0; index < characters.size(); index++) {
                    s[indices[index]] = characters[index]; 
                }
            }
        }
        
        return s; 
    }
};
