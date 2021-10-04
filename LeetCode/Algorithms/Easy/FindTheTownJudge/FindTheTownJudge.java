public class FindTheTownJudge {
        public int findJudge(int N, int[][] trust) {
            // increment the counter for how many trust it has from people,
            // at the end, the person having exactly N - 1 trust is judge
            // otherwise, return -1;
            int[] trustcount = new int[N+1]; // there is no zero person
            for(int[] t : trust){
                trustcount[t[0]]--; // decrementing if person trusts other
                trustcount[t[1]]++; // incrementing if othe trust this person
            }

            for(int i = 1; i <= N; i++){
                if(trustcount[i] == N - 1)
                    return i;
            }
            return -1;
        }
}
/*
 * Complexity
 * Space: O(N) 
 * Time: O(N)
 * */
