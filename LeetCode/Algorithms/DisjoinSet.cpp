#include <bits/stdc++.h>
using namespace std; 
class DisjoinSet {
    vector<int> rank, parent, size; 

public: 
    DisjoinSet(int n) {
        rank.resize(n + 1, 0); 
        size.resize(n + 1, 0); 
        parent.resize(n + 1); 
        for(int i=0; i<=n; i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]); 
    }

    void UnionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 

        if(ulp_u == ulp_v) {
            return; 
        } else if(rank[ulp_v] > rank[ulp_u]) {
            parent[ulp_u] = ulp_v; 
        } else if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u; 
        } else if(rank[ulp_u] == rank[ulp_v]) {
            parent[ulp_v] = ulp_u; 
            rank[ulp_v]++; 
        }
    }

    void UnionBySize(int u, int v) {
            int ulp_u = parent[u]; 
            int ulp_v = parent[v]; 

            if(ulp_u == ulp_v) return;
            if(size[ulp_u] > size[ulp_v]) {
                size[ulp_u] += size[ulp_v]; 
                parent[ulp_v] = ulp_u; 
            } else {
                size[ulp_v] += size[ulp_u];
                parent[ulp_u] = ulp_v; 
            }
    }
};

int main() {
    DisjoinSet ds(7); 
    ds.UnionByRank(1, 2); 
    ds.UnionByRank(2, 3); 
    ds.UnionByRank(4, 5); 
    ds.UnionByRank(6, 7); 
    ds.UnionByRank(5, 6); 
    // ds.UnionByRank(1, 2); 

    // if 3 and 7 same or not
    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout<<"Same"<<endl;
    } else {
        cout<<"Not Same"<<endl;
    }
    ds.UnionByRank(3, 7); 
    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout<<"Same"<<endl;
    } else {
        cout<<"Not Same"<<endl;
    }

    return 0; 
}