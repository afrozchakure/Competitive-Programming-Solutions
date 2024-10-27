class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double glass[101][101] = {0.0}; 
        glass[0][0] = poured; 
        for(int i=0; i<100; i++) {
            for(int j=0; j<=i; j++) {
                if(glass[i][j] >= 1) {
                    glass[i+1][j] += (glass[i][j] - 1) / 2.0; 
                    glass[i + 1][j+1] += (glass[i][j] - 1) / 2.0;
                    glass[i][j] = 1; 
                }
            }
        }

        return glass[query_row][query_glass]; 
    }
};

//      1 
//     1  1
//    1  1  1 


//     1 2 3 4 5 6 


//    (i,j)    (i,j+1)
//    (i+1,j)  (i+1,j+1)