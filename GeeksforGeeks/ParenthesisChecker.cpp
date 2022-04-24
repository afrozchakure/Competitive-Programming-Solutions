public:
    //Function to check if brackets are balanced or not.
bool ispar(string x)
{
// Your code here
stack<char> s; 

for(auto ele: x) {
    if((ele == '}' || ele == ']' || ele == ')') && s.empty()) return false;
    if(ele == '{' || ele == '[' || ele == '(') s.push(ele);
    else if((ele == '}' && s.top() == '{') || (ele == ')' && s.top() == '(' )|| (ele == ']' && s.top() == '[')) s.pop();  
    else 
        return false; 
}

if(s.empty()) return true; 
return false;
}


// Time Complexity - O(N)
// Space Complexity - O(N), since we're using a stack 
