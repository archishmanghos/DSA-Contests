import java.util.HashMap;
import java.util.Map;

public class LC217 {
    public boolean containsDuplicate(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i : nums) {
            if (mp.get(i) != null) return true;
            mp.put(i, 1);
        }

        return false;
    }
}