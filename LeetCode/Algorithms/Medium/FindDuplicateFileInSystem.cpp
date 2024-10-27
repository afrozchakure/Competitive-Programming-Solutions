class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> files; 
        vector<vector<int>> result; 
        for(string &path: paths) {
            stringstream ss(path); 
            string root; 
            string s; 
            getline(ss, root, ' '); 
            while(geline(ss, ))
        }

        return result; 
    }
};