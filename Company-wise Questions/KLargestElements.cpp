class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        priority_queue<int> pq; 
        vector<int> result; 
        // int  = sizeof(arr)/sizeof(arr[0]); 
        for(int i=0; i<n; i++) {
            pq.push(arr[i]); 
        }
        
        for(int i=0; i<k; i++) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};

// time Complexity - O(NlogN), inserting N elements in a priority queue 
// Space Complexity - O(N), N is the number of elements in the array

// Priority Queue is not more efficient than sorting