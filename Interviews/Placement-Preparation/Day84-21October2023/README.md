<h2>73. Set Matrix Zeroes</h2>

[Link to Problem](https://leetcode.com/problems/set-matrix-zeroes)

<details><summary>Codes</summary>

```java
package striver_sde_sheet.array1;

public class P1SMZ {
    public void setZeroes(int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        boolean down = false, right = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0 || j == 0) {
                        matrix[0][0] = 0;
                        if (j == 0) down = true;
                        if (i == 0) right = true;
                    } else {
                        matrix[0][j] = matrix[i][0] = 0;
                    }
                }
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == 0 || j == 0) {
                    if (matrix[0][0] == 0) {
                        if (down && j == 0) matrix[i][j] = 0;
                        if (right && i == 0) matrix[i][j] = 0;
                    }
                } else {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
                }
            }
        }
    }
}
```

</details>
