class RandomizedSet {
public:
    unordered_set<int> set; 
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        set.insert(val); 
    }
    
    bool remove(int val) {
        set.erase(set.find(val)); 
    }
    
    int getRandom() {
        int n = set.size(); 
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */