<h2>97. Interleaving String </h2>

[Link to Problem](https://leetcode.com/problems/interleaving-string/description/)

```java

class Solution {
    int dp(int idx_s1, int idx_s2, int idx_s3, String s1, String s2, String s3, int[][][] cache) {
        boolean check = idx_s1 == s1.length() && idx_s2 == s2.length();
        if (idx_s3 == s3.length()) return (check ? 1 : 0);
        if (check) return 0;
        if (cache[idx_s1][idx_s2][idx_s3] != -1) return cache[idx_s1][idx_s2][idx_s3];

        int answer = 0;
        if (idx_s1 < s1.length() && s1.charAt(idx_s1) == s3.charAt(idx_s3))
            answer |= dp(idx_s1 + 1, idx_s2, idx_s3 + 1, s1, s2, s3, cache);
        if (idx_s2 < s2.length() && s2.charAt(idx_s2) == s3.charAt(idx_s3))
            answer |= dp(idx_s1, idx_s2 + 1, idx_s3 + 1, s1, s2, s3, cache);

        return cache[idx_s1][idx_s2][idx_s3] = answer;
    }

    public boolean isInterleave(String s1, String s2, String s3) {
        int n_s1 = s1.length(), n_s2 = s2.length(), n_s3 = s3.length();
        int[][][] cache = new int[n_s1 + 1][n_s2 + 1][n_s3];
        for (int[][] i : cache) {
            for (int[] j : i) {
                Arrays.fill(j, -1);
            }
        }

        int answer = dp(0, 0, 0, s1, s2, s3, cache);
        return answer == 1;
    }
}

```

<br>
<br>

<h2>128. Longest Consecutive Sequence </h2>

[Link to Problem](https://leetcode.com/problems/longest-consecutive-sequence/description/)

```java

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

```