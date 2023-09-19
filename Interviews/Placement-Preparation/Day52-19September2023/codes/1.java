import java.util.HashSet;
import java.util.Set;

public class LC287 {
    public int findDuplicate(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int i : nums) {
            if (s.contains(i)) return i;
            s.add(i);
        }
        return -1;
    }
}