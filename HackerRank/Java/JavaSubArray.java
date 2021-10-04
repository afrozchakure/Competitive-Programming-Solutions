import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int A[] = new int[n];
        for(int i=0; i<n; i++)
        {
            A[i] = sc.nextInt();
        }
        
        int count = 0;
        
        // To find the number of subarrays whose sum is less than 0
        // Do a double for loop and iterate the second array from i to n
        for(int i=0; i<n; i++)
        {
            int sum = 0;
            for(int j=i; j<n; j++)
            {
                sum += A[j];
                
                if(sum < 0)
                {
                    count++;
                }
            }
        }
        System.out.println(count);
    }
}