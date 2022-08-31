#include<climits>
// Note : Here it is a special case, we are not checking for isFull and isEmpty before pushing and popping from the stack, because for those conditions it'll give TLE
void push(stack<int>& s, int a){
	// Your code goes here
	s.push(a);
// 	minVal = min(minVal, a);
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	if(s.size() == n) {
	    return true;
	}
	return false;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	if(s.size() == 0) {
	    return true;
	}
	return false;
}

int pop(stack<int>& s){
	// Your code goes here
	int a = s.top();
	s.pop();
	return a;
}

int getMin(stack<int>& s){
	// Your code goes here
	int minVal = INT_MAX; 
	stack<int> temp = s; 
	int n = s.size();
	for(int i=0; i<n; i++) {
	    minVal = min(s.top(), minVal);
	    s.pop(); 
	}
	
	s = temp;
	return minVal;
	
}

// Time Complexity: O(N) for getMin, O(1) for remaining all 4 functions.
// Auxiliary Space: O(1) for all the 5 functions.