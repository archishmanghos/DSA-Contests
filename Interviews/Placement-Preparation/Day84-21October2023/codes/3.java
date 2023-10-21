package striver_sde_sheet.array1;

public class P4KA {
    public int maxSubArray(int[] nums) {
        int curSum = 0, maxSum = 0, minNeg = (int) - 1e5;
        for (int i = 0; i < nums.length; i++) {
            curSum += nums[i];
            if (curSum < 0) curSum = 0;
            maxSum = Math.max(maxSum, curSum);
            minNeg = Math.max(minNeg, nums[i]);
        }

        return minNeg >= 0 ? maxSum : minNeg;
    }
}