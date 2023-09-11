import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LC1282 {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        List<List<Integer>> answer = new ArrayList<>();
        Map<Integer, Integer> mp = new HashMap<>();

        for (int i = 0; i < groupSizes.length; i++) {
            int idx;
            if (mp.get(groupSizes[i]) == null || answer.get(mp.get(groupSizes[i])).size() == groupSizes[i]) {
                idx = answer.size();
                answer.add(new ArrayList<>());
            } else {
                idx = mp.get(groupSizes[i]);
            }

            answer.get(idx).add(i);
            mp.put(groupSizes[i], idx);
        }

        return answer;
    }
}