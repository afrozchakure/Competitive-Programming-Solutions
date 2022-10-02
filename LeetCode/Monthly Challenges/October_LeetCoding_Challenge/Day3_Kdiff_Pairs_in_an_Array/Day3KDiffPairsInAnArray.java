class Solution {
    public int findPairs(int[] nums, int k) {
        int count = 0;
        if (nums == null || nums.length == 0 || k < 0)
            return 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : nums) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }

        for (Map.Entry<Integer, Integer> e : map.entrySet()) {
            if (k == 0) {
                if (e.getValue() >= 2) {
                    count++;
                }
            } else {
                if (map.containsKey(e.getKey() + k)) {
                    count++;
                }
            }
        }
        return count;
    }
}
