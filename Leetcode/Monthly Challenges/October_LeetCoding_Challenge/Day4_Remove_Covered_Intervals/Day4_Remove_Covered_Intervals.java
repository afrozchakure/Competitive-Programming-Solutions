class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, (x,y) -> x[0] - y[0]);
        int l = -1;
        int r = -1;
        int count = 0;
        for(int[] interval:intervals){
            if(interval[0] > l && interval[1] > r){
                l = interval[0];
                count++;
            }
            r = Math.max(r, interval[1]);
        }
        return count;
    }
}
