class Solution {
public:
    vector<int> headChar; 

    int find(int x) {
        if(headChar[x] == -1) return x; 

        return headChar[x] = find(headChar[x]); 
    }

    void Union(int x, int y) {
        int parentx = find(x); 
        int parenty = find(y); 

        if(parentx == parenty) return; 

        // make smaller one represent of other, if parent are different 
        headChar[max(parentx, parenty)] = min(parentx, parenty); 
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
         headChar.resize(26, -1); 

         // make group (Union) 
         for(int i=0; i<s1.size(); i++) {
            Union(s1[i] - 'a', s2[i] - 'a'); 
         }    

         // traverse in the baseStr and find the parent of each char 
         for(auto i=0; i<baseStr.size(); i++) {
            baseStr[i] = find(baseStr[i] - 'a') + 'a'; 
         }     
         return baseStr; 
    }
};