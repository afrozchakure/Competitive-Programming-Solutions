class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> cache; 

        return helper(0, cache, books, shelfWidth);
    }

    int helper(int i, vector<int> cache, vector<vector<int>> &books, int shelfWidth) {
        if(i == books.size()) {
            return 0; 
        }

        if(cache.find(i) != cache.end()) {
            return cache[i];
        }

        cur_width = shelfWidth; 

        max_height = 0; 
        cache[i] = INT_MAX;

        for(int j=i; j<books.size(); j++) {
            int width = books[j][0];
            int height = books[j][1];

            if(cur_width < width) {
                break;
            }

            cur_width -= width; 
            max_height = max(max_height, height); 
            res = min(res, helper(j + 1) + max_height);
        }

        return cache[i];
    }
};