class Solution {
public:
    const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; 
    unordered_map<string, string> LongToShort, ShortToLong; 
    // UrlDB - contains all the shortened URls 
    // CodeDB - Contains all the codes; 
    string getCode() {
        string code = ""; 
        for(int i=0; i<6; i++) code += chars[rand() % 62]; 
        return "http://tinyurl.com/" + code; 
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        // To check if shortUrlCode generated is duplicated, we return the longForm of the url
        if(ShortToLong.find(longUrl) != ShortToLong.end()) return ShortToLong[longUrl]; 
        string code = getCode(); 
        
        while(LongToShort.find(code) != LongToShort.end()) code = getCode(); 
        
        LongToShort[longUrl] = code; 
        ShortToLong[code] = longUrl; 
        return code; 
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return ShortToLong[shortUrl]; 
    }
};
// Time complexity - O(1), constant time because of constant retrieval; 
// Space Complexity - O(N), since we're using hashmap

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));