import java.util.HashMap;
import java.util.Map;

public class LC1 {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> index = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (index.get(target - nums[i]) != null) return new int[] {index.get(target - nums[i]), i};
            index.put(nums[i], i);
        }

        return new int[] { -1};
    }
}