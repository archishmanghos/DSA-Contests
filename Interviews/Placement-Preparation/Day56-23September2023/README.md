<h2>1048. Longest String Chain</h2>

[Link to Problem](https://leetcode.com/problems/longest-string-chain)

<details><summary>Codes</summary>

```java
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class LC1048 {
    private Set<Chain> s;

    private int dp(int idx, int n, int[] cache) {
        if (cache[idx] != -1) return cache[idx];
        int answer = 0;
        for (int i = 0; i < n; i++) {
            if (s.contains(new Chain(idx, i))) {
                answer = Math.max(answer, dp(i, n, cache) + 1);
            }
        }

        return cache[idx] = answer;
    }

    private boolean checkChain(String s, String t) { // s --> t
        if (s.length() != t.length() - 1) return false;
        int j = 0;
        boolean skipped = false;

        for (int i = 0; i < t.length() && j < s.length(); i++) {
            if (s.charAt(j) != t.charAt(i)) {
                if (skipped) return false;
                skipped = true;
            } else {
                j++;
            }
        }

        return true;
    }

    record Chain(int sIdx, int tIdx) {
    }

    public int longestStrChain(String[] words) {
        s = new HashSet<>();
        int n = words.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // words[i] ---> words[j]
                if (s.contains(new Chain(j, i))) continue;
                if (checkChain(words[i], words[j])) s.add(new Chain(i, j));
            }
        }

        int answer = 0;
        int[] cache = new int[n];
        Arrays.fill(cache, -1);
        for (int i = 0; i < n; i++) answer = Math.max(answer, dp(i, n, cache) + 1);
        return answer;
    }
}
```

</details>