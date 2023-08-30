import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LC347 {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        int max_count = 0;
        for (int i : nums) {
            mp.merge(i, 1, Integer::sum);
            max_count = Math.max(mp.get(i), max_count);
        }

        List<List<Integer>> bucket = new ArrayList<>(max_count + 1);
        for (int i = 0; i <= max_count; i++) bucket.add(new ArrayList<>());
        for (int i : mp.keySet()) bucket.get(mp.get(i)).add(i);

        int[] answer = new int[k];
        for (int i = max_count, j = 0; i >= 1 && j < k; i--) {
            if (bucket.get(i).size() > 0) {
                for (int ii : bucket.get(i)) answer[j++] = ii;
            }
        }

        return answer;
    }
}