<h2>73. Set Matrix Zeroes</h2>

[Link to Problem](https://leetcode.com/problems/set-matrix-zeroes)

<details><summary>Code</summary>

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

<br>
<br>

<h2>31. Next Permutation</h2>

[Link to Problem](https://leetcode.com/problems/next-permutation)

<details><summary>Code</summary>

```java
package striver_sde_sheet.array1;

public class P3NP {
    private int[] reverse(int[] arr, int idx) {
        int i = idx, j = arr.length - 1;
        while (i < j) {
            arr[i] = arr[i] + arr[j];
            arr[j] = arr[i] - arr[j];
            arr[i] = arr[i] - arr[j];
            i++;
            j--;
        }

        return arr;
    }

    public void nextPermutation(int[] nums) {
        int breakIndex = -1, n = nums.length;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                breakIndex = i;
                break;
            }
        }

        if (breakIndex == -1) {
            nums = reverse(nums, 0);
            return;
        }

        int leastButGreater = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[breakIndex]) {
                leastButGreater = i;
                break;
            }
        }

        nums[breakIndex] = nums[breakIndex] + nums[leastButGreater];
        nums[leastButGreater] = nums[breakIndex] - nums[leastButGreater];
        nums[breakIndex] = nums[breakIndex] - nums[leastButGreater];
        nums = reverse(nums, breakIndex + 1);
    }
}
```

</details>
