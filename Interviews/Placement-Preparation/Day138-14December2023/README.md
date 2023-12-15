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