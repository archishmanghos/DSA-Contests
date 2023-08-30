public class LC2366 {
    public long minimumReplacement(int[] nums) {
        int n = nums.length, last_processed = nums[n - 1];
        long answer = 0;
        for (int i = n - 2; i >= 0; i--) {
            int parts_required = (nums[i] + last_processed - 1) / last_processed;
            last_processed = nums[i] / parts_required;
            answer += parts_required - 1;
        }

        return answer;
    }
}