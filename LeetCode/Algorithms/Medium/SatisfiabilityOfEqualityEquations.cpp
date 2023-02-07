class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        // length of 4 
        vector<int> parent(26); 

        // build the parent map using union find 
        // next when we traverse all != cases, if var1, var2 parent are same but they 
        // they have != relationship, this is not possible -> return false 
        // initially all are there own parent 
        for(int i=0; i<26; i++) {
            parent[i] = i; 
        }

        // traverse all = cases to establish parent-child relationship 
        for(string equation: equations) {
            char equality = equation[1]; 
            if(equality == '=') {
                // find the parent of both 
                int var1 = fetchParent(equation[0] - 'a', parent); 
                int var2 = fetchParent(equation[3] - 'a', parent); 

                if(var1 != var2) {  // unify them
                    parent[var2] = var1; 
                }
            }
        }

        // now traverse all != cases to check if any invalid condition exists 
        for(string equation: equations) {
            char equality = equation[1]; 
            if(equality == '!') {
                int var1 = fetchParent(equation[0] - 'a', parent); 
                int var2 = fetchParent(equation[3] - 'a', parent); 

                if(var1 == var2) {
                    return false; 
                }
            }
        }
        return true; 
    }

    int fetchParent(int index, vector<int> &parent) {
        if(parent[index] == index) {
            return index; 
        }
        return fetchParent(parent[index], parent); 
    }
};

// a == b, b == c, c == d, d != a 


// a = a 
// b = b 
// c = c 
// d = d 
//           a = b  | b == c | c == d  | d != a 
// first     a      | a      | a       | a 
// second    b      | c      | d       | a 

// b = a 
// c = a 
// d = a 

// return false 






