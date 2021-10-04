int sum(int a , int b)
{
    //code here
    if(b == 0)
        return a; 
    else 
    {
        return sum(a ^ b, (unsigned) (a & b) << 1);
    }
    
}

// build a xor function

int sum(int a , int b)
    {
        //code here
        while(b != 0)
        {
            unsigned carry = a&b; 
            a = a ^ b; 
            
            b = carry << 1;
        }
        return a;
        
    }
