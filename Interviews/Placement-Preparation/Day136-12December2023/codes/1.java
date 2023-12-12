public class LC1464 {
    public int maxProduct(int[] nums) {
        int lastGreatest = nums[0] - 1, answer = 0;
        for (int i = 1; i < nums.length; i++) {
            answer = Math.max(answer, lastGreatest * (nums[i] - 1));
            lastGreatest = Math.max(lastGreatest, nums[i] - 1);
        }

        return answer;
    }
}
