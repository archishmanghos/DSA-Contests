import java.util.HashMap;
import java.util.Map;

public class LC128 {
    public int longestConsecutive(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int num : nums) mp.put(num, 1);
        int answer = 0;
        for (int num : nums) {
            if (mp.get(num) == 1 && mp.get(num + 1) == null) {
                int k = num;
                while (mp.get(k) != null && mp.get(k) != 0) k--;
                answer = Math.max(answer, num - k);
            }
        }

        return answer;
    }
}