<h2>746. Min Cost Climbing Stairs</h2>

[Link to Problem](https://leetcode.com/problems/min-cost-climbing-stairs)

<details><summary>Codes</summary>

```java
import java.util.Arrays;

public class LC746 {
    private int dp(int idx, int[] cost, int[] cache) {
        if (idx >= cost.length) return 0;
        if (cache[idx] != -1) return cache[idx];

        int answer = Math.min(dp(idx + 1, cost, cache), dp(idx + 2, cost, cache)) + cost[idx];
        return cache[idx] = answer;
    }

    public int minCostClimbingStairs(int[] cost) {
        int[] cache = new int[cost.length];
        Arrays.fill(cache, -1);
        return Math.min(dp(0, cost, cache), dp(1, cost, cache));
    }
}
```

</details>