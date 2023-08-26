<h2>2262. Total Appeal of A String </h2>

[Link to Problem](https://leetcode.com/problems/total-appeal-of-a-string/description/)

```java

public class LC2262 {
    public static long appealSum(String s) {
        int n = s.length();
        long answer = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            int totalSubstrings = n * (n + 1) / 2, prev = -1;
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == c) {
                    int characters_between = (i - prev - 1);
                    totalSubstrings -= characters_between * (characters_between + 1) / 2;
                    prev = i;
                }
            }
            int characters_between = (n - prev - 1);
            totalSubstrings -= characters_between * (characters_between + 1) / 2;
            answer += totalSubstrings;
        }

        return answer;
    }
}

```

<br>
<br>

<h2>646. Maximum Length of Pair Chain </h2>

[Link to Problem](https://leetcode.com/problems/maximum-length-of-pair-chain/description/)

```java

import java.util.Arrays;
import java.util.Comparator;

public class LC646 {
    int dp(int idx, int lastIdx, int[][] pairs, int[][] cache) {
        if (idx == pairs.length) return 0;
        if (cache[idx][lastIdx] != -1) return cache[idx][lastIdx];

        int answer = dp(idx + 1, lastIdx, pairs, cache);
        if (lastIdx == 0 || pairs[lastIdx - 1][1] < pairs[idx][0])
            answer = Math.max(answer, dp(idx + 1, idx + 1, pairs, cache) + 1);

        return cache[idx][lastIdx] = answer;
    }

    public int findLongestChain(int[][] pairs) {
        int n = pairs.length;
        Arrays.sort(pairs, Comparator.comparingInt(a -> a[0]));
        int[][] cache = new int[n][n + 1];
        for (int[] i : cache) Arrays.fill(i, -1);
        return dp(0, 0, pairs, cache);
    }
}

```