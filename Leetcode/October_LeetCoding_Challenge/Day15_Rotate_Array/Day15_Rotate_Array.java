class Solution {
    public void rotate(int[] nums, int k) {
            k %= nums.length;
            reverse(nums, 0, nums.length - 1);
            reverse(nums, 0, k- 1);
            reverse(nums, k, nums.length - 1);
        
    }
    void reverse(int[] a, int start, int end){
        
        while(start < end){
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
            start++;end--;
        }
    }
}

