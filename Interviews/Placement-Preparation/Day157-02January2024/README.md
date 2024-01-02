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

<h2>2610. Convert an Array Into a 2D Array With Conditions</h2>

[Link to Problem](https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions)

<details><summary>Code</summary>

```java
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LC2610 {
    static class MutableInt {
        int v = 1;

        void increment() { ++v; }

        void decrement() { --v; }

        int get() { return v; }
    }

    public List<List<Integer>> findMatrix(int[] nums) {
        Map<Integer, MutableInt> mp = new HashMap<>();
        for (int i : nums) {
            if (mp.get(i) == null) mp.put(i, new MutableInt());
            else mp.get(i).increment();
        }

        List<List<Integer>> answer = new ArrayList<>();
        boolean flag;
        int idx = 0;
        do {
            flag = false;
            for (int key : mp.keySet()) {
                if (mp.get(key).get() > 0) {
                    flag = true;
                    if (answer.size() == idx) answer.add(new ArrayList<>());
                    answer.get(idx).add(key);
                    mp.get(key).decrement();
                }
            }
            ++idx;
        } while (flag);

        return answer;
    }
}
```

</details>

<br>
<br>