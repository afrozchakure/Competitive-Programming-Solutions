#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Solution {
    //Write your code here
    public:
    stack <char> s;
    queue <char> q;
    void pushCharacter(char i)
    {
        s.push(i);
    }
    void enqueueCharacter(char ch)
    {
        q.push(ch);
    }
    char popCharacter()
    {
        char popped = s.top();
        s.pop();
        return popped;
    }
    char dequeueCharacter() 
    {
        char dequeued = q.front();
        q.pop();
        return dequeued;
    }
};

int main() {
    // read the string s.
    string s;
    getline(cin, s);
    
  	// create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;
}

// Remember Queue and Stack STL have both the push() and pop() functions 
// Just that Queue has q.front() function and s.top() function to access front element of queue and top element of stack
