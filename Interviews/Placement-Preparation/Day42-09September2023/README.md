<h2>377. Combination Sum IV</h2>

[Link to Problem](https://leetcode.com/problems/combination-sum-iv)

<details><summary>Codes</summary>

```java
import java.util.Arrays;

public class LC377 {
    public int dp(int[] nums, int target, int[] cache) {
        if (target == 0) return 1;
        if (cache[target] != -1) return cache[target];

        int answer = 0;
        for (int num : nums) {
            if (num <= target) {
                answer += dp(nums, target - num, cache);
            }
        }

        return cache[target] = answer;
    }

    public int combinationSum4(int[] nums, int target) {
        int[] cache = new int[target + 1];
        Arrays.fill(cache, -1);
        return dp(nums, target, cache);
    }
}
```

</details>