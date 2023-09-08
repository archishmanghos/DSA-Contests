import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LC15 {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> answer = new ArrayList<>();

        for (int i = 0; i + 2 < nums.length; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int j = i + 1, k = nums.length - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    answer.add(new ArrayList<>());
                    answer.get(answer.size() - 1).add(nums[i]);
                    answer.get(answer.size() - 1).add(nums[j]);
                    answer.get(answer.size() - 1).add(nums[k]);
                    j++;
                    while (j < k && nums[j - 1] == nums[j]) j++;
                    k--;
                    while (j < k && nums[k + 1] == nums[k]) k--;
                } else if (sum < 0) {
                    j++;
                    while (j < k && nums[j - 1] == nums[j]) j++;
                } else {
                    k--;
                    while (j < k && nums[k + 1] == nums[k]) k--;
                }
            }
        }

        return answer;
    }
}