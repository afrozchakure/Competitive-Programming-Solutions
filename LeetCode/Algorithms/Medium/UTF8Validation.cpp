class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int rbytes = 0; 

        for(int &val: arr) {
            if(rbytes == 0) {
                if(val >> 7 == 0b0) {  // 1st bytes of 1 length char 
                    rbytes = 0; 
                } else if(val >> 5 == 0b110) { // 1st bytes of 2nd length char 
                    rbytes = 1; 
                } else if(val >> 4 == 0b1110) { // 1st bytes of 3rd length  
                    rbytes = 2; 
                } else if(val >> 3 == 0b11110) { // 1st bytes of 4th length char 
                    rbytes = 3; 
                } else {
                    return false; 
                }
            } else {
                if(val >> 6 == 0b10) {
                    rbytes--; 
                } else {
                    return false; 
                }
            }
        }      
        if(rbytes == 0)
            return true; 
        return false; 
    }
};


1b ===   0 
2b ===   1 1 0 _ _ _ _ _  
3b ==    1 1 1 0 _ _ _ _  
4b ===   1 1 1 1 0 _ _ _ 

> 1 0 _ _ _ _ _ _ 