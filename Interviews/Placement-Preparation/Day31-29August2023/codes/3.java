public class LC238 {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] answer = new int[n];
        int current_product = 1;

        for (int i = 0; i < n; i++) {
            answer[i] = current_product;
            current_product *= nums[i];
        }

        current_product = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= current_product;
            current_product *= nums[i];
        }

        return answer;
    }
}