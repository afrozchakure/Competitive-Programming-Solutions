#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;
    Difference(vector<int> a)
    {
        this->elements = a;
    }
    void computeDifference()
    {
        int smallest = elements[0];
        int largest = elements[0];

        int n = elements.size();
        for(int i=0; i<n; i++)
        {
            if(elements[i] < smallest) smallest = elements[i];
            if(elements[i] > largest ) largest = elements[i];
        }
        maximumDifference = largest - smallest;
    }
	// Add your code here

}; // End of Difference class

int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}

// Time Complexity - O(n)
// Space Complexity - O(1)

// You don't need to reinitialize maxDifference like ``int maxDifference = 0``, 
// Just need to assign the value to maxDifference


/*
void computeDifference()
    {
        int n = elements.size();
        sort(elements.begin(), elements.end());
        maximumDifference = elements[n-1] - elements[0];
        
    }

// Time Complexity - O(nlogn)
// Space Complexity - O(1)
*/