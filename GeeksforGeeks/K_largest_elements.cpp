vector<int> kLargest(int arr[], int n, int k)
{
    // code here
    priority_queue<int> pq;  
    vector<int> result; 
    
    for(int i=0; i<n; i++) // - N 
    {
        pq.push(arr[i]);
    }
    
    for(int i=0; i<k; i++) // - K Times loop 
    {
        result.push_back(pq.top()); 
        pq.pop();  // -  log(N) for internal sorting
    }
    return result; 
}

// Time Complexity - O(N + Klog(N))
// Space Complexity - O(N), storing N elements in priority queue

// If you want to have min-heap 
priority_queue<int, vector<int>, greater<int> > q;     
