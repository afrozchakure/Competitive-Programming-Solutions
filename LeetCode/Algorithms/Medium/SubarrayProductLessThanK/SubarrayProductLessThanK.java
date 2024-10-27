public class SubarrayProductLessThanK {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1) return 0;

        int count = 0;
        int prod = 1;

        // sliding window;
        int left = 0, right = 0;

        while (right < nums.length) {
            prod *= nums[right];
            while (prod >= k) {
                prod /= nums[left];
                left++;
            }

            count += right - left + 1; // + 1 for individual numbers also
            right++;
        }

        return count;
    }
}

