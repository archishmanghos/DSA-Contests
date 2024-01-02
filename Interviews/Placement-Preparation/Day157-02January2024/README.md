<h2>2343. Query Kth Smallest Trimmed Number</h2>

[Link to Problem](https://leetcode.com/problems/query-kth-smallest-trimmed-number)

<details><summary>Code</summary>

```java
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class LC2343 {
    static class pair {
        private final String f;
        private final int s;

        pair(String f, int s) {
            this.f = f;
            this.s = s;
        }

        public int getS() {
            return s;
        }
    }

    public int[] smallestTrimmedNumbers(String[] nums, int[][] queries) {
        int n = nums.length, n1 = nums[0].length(), ql = queries.length;
        int[] answer = new int[ql];
        for (int q = 0; q < ql; q++) {
            int k = queries[q][0], trim = queries[q][1];
            String[] a = new String[n];
            for (int i = 0; i < n; i++) {
                a[i] = nums[i].substring(n1 - trim);
            }
            List<pair> li = new ArrayList<>(n);
            for (int i = 0; i < n; i++) li.add(new pair(a[i], i));
            System.out.println();
            li.sort(Comparator.comparing(o -> o.f));
            answer[q] = li.get(k - 1).getS();
        }

        return answer;
    }
}
```

</details>

<br>
<br>