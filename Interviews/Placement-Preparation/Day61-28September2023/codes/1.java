public class LC905 {
    public int[] sortArrayByParity(int[] nums) {
        int i = 0, j = nums.length - 1;
        while (i < j) {
            if (nums[i] % 2 == 1) {
                if (nums[j] % 2 == 0) {
                    nums[i] += nums[j];
                    nums[j] = nums[i] - nums[j];
                    nums[i] = nums[i] - nums[j];
                    i++;
                }
                j--;
            } else {
                if (nums[j] % 2 == 1) j--;
                i++;
            }
        }

        return nums;
    }
}