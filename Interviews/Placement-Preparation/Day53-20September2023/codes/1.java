public class LC1658 {
    public int minOperations(int[] nums, int x) {
        int n = nums.length;
        int[] pref = new int[n];
        int[] suff = new int[n];
        pref[0] = nums[0];
        suff[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + nums[i];
        for (int i = n - 2; i >= 0; i--) suff[i] = suff[i + 1] + nums[i];

        int answer = -1;
        for (int i = 0; i <= n; i++) {
            int leftSum = i > 0 ? pref[i - 1] : 0;
            if (leftSum == x) {
                answer = answer == -1 ? i : Math.min(answer, i);
                continue;
            }

            if (leftSum > x) break;

            int low = i, high = n - 1, target = x - leftSum;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (suff[mid] == target) {
                    answer = answer == -1 ? i + n - mid : Math.min(answer, i + n - mid);
                    break;
                }
                if (suff[mid] > target) low = mid + 1;
                else high = mid - 1;
            }
        }

        return answer;
    }
}