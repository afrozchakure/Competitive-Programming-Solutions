package Medium;

import java.util.*;

public class TrainsAndPlatform {
    class Train {
        public int arrival, departure;

        public Train(int arrival, int departure) {
            this.arrival = arrival;
            this.departure = departure;
        }
    }
    // Greedy approach
//    Time Complexity: O(n * log(n))
//    Auxiliary Space Complexity: O(1)
    int minPlatforms(Train[] trains) {
        int n = trains.length;
        int reqPlatform = 0;
        int[] arrival = new int[n];
        int[] dep = new int[n];
        for (int i = 0; i < n; i++) {
            arrival[i] = trains[i].arrival;
            dep[i] = trains[i].departure;
        }
        // Step1: sort arrival and dept
        Arrays.sort(arrival);
        Arrays.sort(dep);

        //
        int i = 0, j = 0, platform = 0;
        while (i < n && j < n) {
            // if arrival time is before depture, then we need a platform
            if (arrival[i] <= dep[j]) {
                platform++;
                i++;
                reqPlatform = Math.max(reqPlatform, platform);
            } else {
                // if arrival is after dept time, then we reduce the platform
                platform--;
                j++;
            }
        }
        return reqPlatform;

    }
}

/*
* 2
4
120 130
130 150
125 145
150 180
7
360 400
320 380
260 320
210 250
420 450
440 480
370 420
*
* output : 3
* 3
* */
