class Solution {
public:
    bool diff(string &a, string &b) {
        if(a.size() != b.size()) return false; 
        int cnt = 0; 
        for(int i=0; i<a.size(); i++) {
            if(a[i] != b[i]) {
                cnt++;
            }
        }
        return cnt == 1; 
    }
    int minMutation(string start, string end, vector<string>& bank) {
        int n = bank.size(); 
        map<string, vector<string>> adj;  // adjacency list
        // contains, from each string how many strings can you go

        for(int i=0; i<n; i++) {
            for(int j=i + 1; j < n; j++) {
                if(diff(bank[i], bank[j])) {
                    adj[bank[i]].push_back(bank[j]); 
                    adj[bank[j]].push_back(bank[i]); 
                }
            }
        }  

        // just connect the starting node to all the nodes you can go to 
        for(int i=0; i<n; i++) {
            if(diff(bank[i], start)) {
                adj[bank[i]].push_back(start); 
                adj[start].push_back(bank[i]); 
            }
        }  

        queue<string> q; 
        q.push(start); 
        set<string> st; 
        st.insert(start); 
        int ans = 0; 
        while(!q.empty()) {
            int sz = q.size(); 
            while(sz--) {
                string node = q.front(); q.pop(); 
                for(auto &e: adj[node]) {
                    if(st.count(e) == 0) {
                        st.insert(e); 
                        q.push(e); 
                    }
                }
            }
            ans++; 
            if(st.count(end)) return ans; 
        }   
        return -1;  
    }
};

