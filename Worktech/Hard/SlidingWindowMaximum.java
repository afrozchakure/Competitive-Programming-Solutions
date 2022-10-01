package Hard;

import java.util.*;

public class SlidingWindowMaximum {
    // O(n) o(n)
    int[] maxSlidingWindow(int[] A, int k) {
        if (A == null || A.length == 0 || k <= 0) {
            return new int[0];
        }
        int n = A.length;
        if (k == 1) {
            return Arrays.copyOf(A, n);
        }

        int[] res = new int[n - k + 1];
        int indx = 0;

        Deque<Integer> pq = new ArrayDeque<Integer>(k); // queue of max size k

        //Make sure that the queue's First element has index that is always the largest within the window
        for(int i = 0; i < n; i++){
            // if max element is out of the sliding window, then remove it from first place
            while(!pq.isEmpty() && i - pq.getFirst() == k){
                pq.removeFirst();
            }

            // if current element  A[i] is greater than smallest index ie pq.getLast()
            // such that we always remove the smaller element from queue.
            while(!pq.isEmpty() && A[pq.getLast()] < A[i]){
                pq.removeLast();
            }

            pq.addLast(i); // add the new indexes to last


            // for every sliding window made, add the queue's first index
            if(i >= k - 1){
                res[indx++] = A[pq.getFirst()];
            }


        }


        return res;

    }

}

