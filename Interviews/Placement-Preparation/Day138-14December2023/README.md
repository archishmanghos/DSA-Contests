<h2>2482. Difference Between Ones and Zeros in Row and Column</h2>

[Link to Problem](https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column)

<details><summary>Code</summary>

```java
public class LC2482 {
    public int[][] onesMinusZeros(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[] cols = new int[m];
        int[] rows = new int[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        int[][] answer = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                answer[i][j] = n + m - 2 * (rows[i] + cols[j]);
            }
        }

        return answer;
    }
}
```

</details>

<br>
<br>

<h2>1436. Destination City</h2>

[Link to Problem](https://leetcode.com/problems/destination-city)

<details><summary>Code</summary>

```java
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LC1436 {
    static class MutableInt {
        int value = 0;
        public void increment() { ++value; }
        public void decrement() { --value; }
        public int get() { return value; }
    }

    public String destCity(List<List<String>> paths) {
        Map<String, MutableInt> mp = new HashMap<>();
        for (var path : paths) {
            String u = path.get(0), v = path.get(1);

            if (mp.get(u) == null) mp.put(u, new MutableInt());
            mp.get(u).increment();

            if (mp.get(v) == null) mp.put(v, new MutableInt());
            mp.get(v).decrement();
        }

        for (String key : mp.keySet()) { if (mp.get(key).get() == -1) return key; }

        return "-1";
    }
}
```

</details>