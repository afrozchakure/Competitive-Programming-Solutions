void sort012(int a[], int n)
{
    int ones = 0; 
    int zeros = 0;
    int twos = 0; 
    
    for(int i=0; i<n; i++)
    {
        if(a[i] == 1)
            ones++;
        else if(a[i] == 2)
            twos++; 
        else if(a[i] == 0)
            zeros++;
    }
    
    int i=0;
    while(zeros--)
    {
        a[i++] = 0;
    }
    while(ones--)
    {
        a[i++] = 1;
    }
    while(twos--)
    {
        a[i++] = 2;
    }
    
}

// Time Complexity - O(N)
// Space complexity - O(1)
