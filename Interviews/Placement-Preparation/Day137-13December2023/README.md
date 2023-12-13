<h2>88. Merge Sorted Array</h2>

[Link to Problem](https://leetcode.com/problems/merge-sorted-array)

<details><summary>Code</summary>

```java
package striver_sde_sheet.array2;

public class LC88 {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if (n >= 0) System.arraycopy(nums2, 0, nums1, m, n);

        int gap = m + n;
        do {
            gap = (gap + 1) / 2;
            int i = 0, j = i + gap;

            while (j < m + n) {
                if (nums1[i] > nums1[j]) {
                    nums1[i] = nums1[i] + nums1[j];
                    nums1[j] = nums1[i] - nums1[j];
                    nums1[i] = nums1[i] - nums1[j];
                }

                i++; j++;
            }
        } while (gap > 1);
    }
}
```

</details>

<br>
<br>

<h2>1582. Special Positions in a Binary Matrix</h2>

[Link to Problem](https://leetcode.com/problems/special-positions-in-a-binary-matrix)

<details><summary>Code</summary>

```java
import java.util.ArrayList;
import java.util.List;

public class LC1582 {
    public int numSpecial(int[][] mat) {
        List<Integer> rows = new ArrayList<>();
        List<Integer> cols = new ArrayList<>();

        for (int i = 0; i < mat.length; i++) {
            int one = 0;
            for (int j = 0; j < mat[0].length; j++) {
                if (mat[i][j] == 1) one++;
            }

            if (one == 1) rows.add(i);
        }

        for (int i = 0; i < mat[0].length; i++) {
            int one = 0;
            for (int[] ints : mat) {
                if (ints[i] == 1) one++;
            }

            if (one == 1) cols.add(i);
        }

        int answer = 0;
        for (int i : rows) {
            for (int j : cols) {
                if (mat[i][j] == 1) answer++;
            }
        }

        return answer;
    }
}
```

</details>