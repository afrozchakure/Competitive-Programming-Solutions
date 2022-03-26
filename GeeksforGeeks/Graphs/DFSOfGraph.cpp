#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 

class Solution {

void DFSUtils(int i, int V, vector<int> adj[], vector<int> &res, vector<bool> &visited) {
        if(visited[i] == true) return; 
        
        visited[i] = true; 
        res.push_back(i); 
        
        for(int j: adj[i]) {
            if(!visited[j]) {
                DFSUtils(j, V, adj, res, visited); 
            }
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false); 
        
        vector<int> res; 
        
        for(int i=0; i<V; ++i) {
            if(!visited[i]) {
                DFSUtils(i, V, adj, res, visited); 
            }
        }
        return res;
        
    }
};

// Time Complexity - O(V + E), V is the number of vertices and E is the number of edges 
// Space Complexity - O(V), V is the number of vertices 