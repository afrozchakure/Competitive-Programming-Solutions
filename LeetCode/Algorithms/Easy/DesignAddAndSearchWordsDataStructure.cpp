class WordDictionary {
    vector<WordDictionary*> children; 
    bool isEndOfWord; 
public:
    WordDictionary(): isEndOfWord(false){
       children = vector<WordDictionary*>(26, nullptr);  
    }
    
    void addWord(string word) {
        WordDictionary *curr = this; 
        for(char c: word) {
            if(curr->children[c - 'a'] == NULL) {
                curr->children[c - 'a'] = new WordDictionary(); 
            }
            curr = curr->children[c - 'a']; 
        }    
        curr->isEndOfWord = true; 
    }
    
    bool search(string word) {
        WordDictionary *curr = this; 
        for(int i=0; i<word.size(); i++) {
            char c = word[i]; 
            if(c == '.') {
                for(auto ch: curr->children) {
                    if(ch && ch->search(word.substr(i + 1))) return true; 
                }
                return false; 
            }
            if(curr->children[c - 'a'] == NULL) return false; 
            curr = curr->children[c - 'a']; 
        }
        return curr && curr->isEndOfWord; 
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */