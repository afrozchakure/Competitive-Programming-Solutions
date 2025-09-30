class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") {
            return "0";
        }

        int m = num1.size(); 
        int n = num2.size(); 

        vector<int> result(m + n, 0); 

        reverse(num1.begin(), num1.end()); 
        reverse(num2.begin(), num2.end()); 

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int digit = (num1[i] - '0') * (num2[i] - '0'); 

                result[i + j] += digit; 
                result[i + j + 1] += (result[i + j] / 10);
                result[i + j] = result[i + j] % 10; 
            }
        }

        reverse(result.begin(), result.end()); 
        int begin = 0; 
        while(begin < result.size() && result[begin] == 0) {
            begin++; 
        }
        
        string output = ""; 
        for(int i=begin; i<result.size(); i++) {
            output += result[i]; 
        }
        return output; 
    }
};