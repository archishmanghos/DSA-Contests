<h2>1235. Maximum Profit in Job Scheduling</h2>

[Link to Problem](https://leetcode.com/problems/maximum-profit-in-job-scheduling)

<details><summary>Code</summary>

```java
import java.util.*;

public class LC1235 {
    List<List<Integer>> period;
    private int dp (int idx, int[] cache) {
        if (idx == period.size()) return 0;
        if (cache[idx] != -1) return cache[idx];

        int nextIdx = period.size(), low = idx + 1, high = period.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (period.get(mid).get(0) >= period.get(idx).get(1)) {
                nextIdx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cache[idx] = Math.max(dp(idx + 1, cache), dp(nextIdx, cache) + period.get(idx).get(2));
        return cache[idx];
    }
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        int[] cache = new int[n];
        Arrays.fill(cache, -1);
        period = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            period.add(new ArrayList<>());
            period.get(i).add(startTime[i]);
            period.get(i).add(endTime[i]);
            period.get(i).add(profit[i]);
        }
        period.sort(Comparator.comparingInt(a -> a.get(0)));
        return dp (0, cache);
    }
}
```

</details>

<br>
<br>