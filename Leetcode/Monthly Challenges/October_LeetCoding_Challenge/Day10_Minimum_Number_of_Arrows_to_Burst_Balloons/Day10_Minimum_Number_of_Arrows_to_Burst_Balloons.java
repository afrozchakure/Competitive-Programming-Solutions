class Solution {
    public int findMinArrowShots(int[][] points) {
          if(points == null || points.length== 0)
            return 0;
        Arrays.sort(points, Comparator.comparingInt(a -> a[1]));
        int pos = points[0][1];
        int count = 1;
        for(int i = 1; i < points.length; i++){
            if(pos >= points[i][0])
                continue;
            count++;
            pos = points[i][1];
        }
        return count;
    }
}
