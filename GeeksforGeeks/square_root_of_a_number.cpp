// linear search approach (time inefficient)
long long int floorSqrt(long long int x) 
{
    // Your code goes here   
    
    if(x == 0 || x == 1)
        return x; 
    long long int result = 1; 
    long long int i = 1; 
    
    while(result <= x)
    {
        i++;
        result = i * i; 
    }
    return i-1; 
}

// Time Complexity - O(n ** 0.5) 
// Space Complexity - O(1)

// Binary Search approach (Better approach)
long long int floorSqrt(long long int x) 
{
    // Your code goes here   
    
    long long int mid; 
    
    long long int start = 1; 
    long long int end = x; 
    long long int ans = 0; 
    while(start <= end)
    {
        mid = (start + end) / 2; 
        
        if(mid * mid == x) // remember mid * mid 
        {
            return mid;
        }
        
        if(mid <= x / mid)
        {
            start = mid + 1;  // similar to binary search, no change
            ans = mid; // set latest mid value to ans
        }
        else 
        {
            end = mid - 1; 
        }
    }
    return ans; 
}

// time Complexity - O(nlogN)
// Space Complexity - O(1)
