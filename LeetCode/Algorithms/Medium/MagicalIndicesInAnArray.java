import java.util.*; 
import java.util.io; 


public class MagicalIndicesInAnArray {

int MagicalIndices(int A[], int n) {
    int i, j, count = 0; 

    int parent[] = new int[n+1]; 
    int visited[] = new int[n+1]; 

    for(int i=0; i<n; i++) {
        parent[i] = -1; 
        visited[i] = 0; 
    }

    for(int i =0; i<n; i++) {

        j = i; 

        // if the current node is not traversed yet 
        if(parent[j] == -1) {

            // traverse the graph until an already visitd node is not found 
            while(parent[j] == -1) {
                parent[j] = i; 
                j = (A[j] + j + 1) % n; 
            }

            // checking the parent value to ensure a value is presnt 
            if(parent[j] == i) {
                // count number of nodes in the cycle 
                while(visited[j] == 0) {
                    visited[j] = 1; 
                    count++; 
                    j = (j + A[i] + 1) % n; 
                }
            }
        }
        return count; 
    }
    }


    public static void main(String args[]) {
        int A[] = {0, 0, 0, 2}; 
        int n = A.length; 
        return 0; 
    }
}

// Time Complexity - O(N) 
// Space Complexity - O(1) 