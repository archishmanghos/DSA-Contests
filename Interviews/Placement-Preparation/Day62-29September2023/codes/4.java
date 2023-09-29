public class LC896 {
    public boolean isMonotonic(int[] nums) {
        boolean incr = true, decr = true;
        for (int i = 1; i < nums.length; i++) {
            incr &= nums[i] >= nums[i - 1];
            decr &= nums[i] <= nums[i - 1];
        }

        return incr || decr;
    }
}