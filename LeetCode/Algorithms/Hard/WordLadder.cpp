#include <set>
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s; 

        for(string str: wordList) {
            s.insert(str);
        }      

        s.insert(beginWord); 
        map<string, vector<string>> map; 

        buildGraph(map, s); 

        set<string> visited; 
        queue<string> q; 

        q.push(beginWord); 

        int level = 0; 
        while(!q.empty()) {
            int size = q.size(); 
            while(size-- > 0) {
                string head = q.front(); 
                q.pop(); 
                if(head == endWord) {
                    return level+1; 
                }

                if(visited.find(head) != visited.end()) {
                    continue; 
                } 

                for(string connection: map[head]) {
                    if(!visited.count(connection)) {
                        q.push(connection); 
                    }
                }
                visited.insert(head); 
            }
            level++; 
        }

        if(visited.count(endWord)) {
            return level; 
        } else {
            return 0; 
        }
    }

    void buildGraph(map<string, vector<string>> map, set<string> wordSet) {
         for(string el: wordSet) {
            for(string innerEl: wordSet) {
                if(el == innerEl) {
                    continue; 
                } else {
                    if(stringsDifferByOne(el, innerEl)) {
                        // el to innerEl 
                        vector<string> connections = map[el];
                        connections.push_back(innerEl); 
                        map[el] = connections; 

                        // innerEl to El
                        vector<string> connectionsForIEl = map[innerEl];
                        connectionsForIEl.push_back(el); 
                        map[innerEl] = connections;
                    }
                }
            }
         }
    }

    bool stringsDifferByOne(string a, string b) {
        if(a.size() != b.size()) {
            return false; 
        } else {
            bool foundOneDifference = false; 
            for(int i=0; i<a.size(); i++) {
                char aChar = a[i]; 
                char bChar = b[i]; 
                if(aChar != bChar) {
                    if(foundOneDifference) {
                        return false; 
                    }
                    foundOneDifference = true; 
                }
            }
        }
        return true; 
    }
};