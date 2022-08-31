// - Time Complexity : O(NxW^2)
// - Space Complexity : O(NxW^2)
// - N: Number of word in words
// - W: Size of a word
class WordFilter {
public:
    unordered_map<string, int> map; 
    WordFilter(vector<string>& words) {
        int n = words.size(); 
        
        for(int i=0; i<n; i++) {
            string word = words[i]; 
            int word_size = word.size();
            
            for(int j=1; j<=word_size; j++) {
                string prefix = word.substr(0, j);
                for(int k=0; k<word_size; k++) {
                    string suffix = word.substr(k, word_size); 
                    map[prefix + "|" + suffix] = i+1; 
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string str = prefix +  "|" + suffix; 
        return map[str] - 1; 
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */