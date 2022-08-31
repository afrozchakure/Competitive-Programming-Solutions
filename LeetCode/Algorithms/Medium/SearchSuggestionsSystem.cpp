class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result; 
        int left = 0, right = products.size() - 1; 
        
        sort(products.begin(), products.end()); 
        for(int i=0; i<searchWord.size(); i++) {
            char m = searchWord[i]; 
            
            while(left <= right && (products[left].size() < i || products[left][i] != m)) {
                left++; 
            }    
            
            while(left <= right && (products[right].size() < i || products[right][i] != m)) {
                right--; 
            }
            
            int length = right - left + 1; 
            vector<string> innerResult; 
            for(int j=0; j<min(3, length); j++) {
                innerResult.push_back(products[j + left]); 
            }
            result.push_back(innerResult); 
        }
        return result; 
    }
};

// Time Complexity - O(nLogn + n x W + m)
// since we are sorting the products vector, then we are iterating n (size of products vector) times W (size of each word)
// m is the size of the searchWord we are iterating. 

