class Solution {
public:
    int calculate(string s) {
        int n = s.size(); 
        int ans = 0; 
        int sign = 1; 
        int currNo = 0;
        stack<int> stk;  
        for(int i=0; i<n; i++) {
            if(isdigit(s[i])) {
                currNo = s[i] - '0'; 
                while(i + 1 < n && isdigit(s[i+1])) {
                    currNo = 10 * currNo + (s[i + 1] - '0'); 
                    i++; 
                }
                currNo = currNo * sign; 
                ans += currNo; 
                currNo = 0; 
            } else if(s[i] == '+') {
                sign = 1; 
            } else if(s[i] == '-') {
                sign = -1; 
            } else if(s[i] == '(') {
                stk.push(ans); 
                stk.push(sign); 
                sign = 1; 
                ans = 0; 
            } else if(s[i] == ')') {
                int prevSign = stk.top(); stk.pop(); 
                int prevNo = stk.top(); stk.pop(); 
                ans = prevSign * ans; 
                ans += prevNo; 
            }
        } 
        return ans; 
    }
};

// Whenever calculator is used, solve using stack 

// '+', '-', '(', ')' and ''

// Sign --> +(1) 
// Curr No ---> 0 --> 12 
// Ans ---> 0 --> 12 (Sign * Curr No)