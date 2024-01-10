import java.util.ArrayList;
import java.util.List;

public class LC300 {
    public int lengthOfLIS(int[] nums) {
        List<Integer> li = new ArrayList<>();
        int answer = 0;

        for (int i : nums) {
            if (li.isEmpty() || i > li.get(li.size() - 1)) {
                li.add(i);
                answer = answer + 1;
            } else {
                int lo = 0, hi = li.size() - 1, idx = -1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (li.get(mid) >= i) {
                        idx = mid;
                        hi = mid - 1;
                    } else {
                        lo = mid + 1;
                    }
                }
                li.set(idx, i);
            }
        }

        return answer;
    }
}