import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {


    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int[][] arr = new int[6][6];

        for (int i = 0; i < 6; i++) {
            String[] arrRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 6; j++) {
                int arrItem = Integer.parseInt(arrRowItems[j]);
                arr[i][j] = arrItem;
            }
        }
        int max_val = Integer.MIN_VALUE;
        for(int i=0; i<=3; i++)
        {
            for(int j=0; j<=3; j++)
            {
                int top = arr[i][j] + arr[i][j+1] + arr[i][j+2];
                int middle = arr[i+1][j+1];
                int down = arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
                int temp_sum = top + middle + down;
          what is the m      
                max_val = Math.max(temp_sum, max_val);
            }
        }
        System.out.print(max_val);
        scanner.close();
    }
}
