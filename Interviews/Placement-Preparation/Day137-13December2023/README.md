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

<br>
<br>

<h2>G. White-Black Balanced Subtrees</h2>

[Link to Problem](https://codeforces.com/problemset/problem/1676/G)

<details><summary>Code</summary>

```java
package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class G_1676 {
    static final Map<Integer, List<Integer>> adj = new HashMap<>();
    static String colour;
    static int answer;

    static int getBalanced(int node, int parent) {
        int balance = colour.charAt(node - 1) == 'W' ? 1 : -1;
        for (int child : adj.getOrDefault(node, new ArrayList<>())) {
            if (child != parent) {
                balance += getBalanced(child, node);
            }
        }

        answer += balance == 0 ? 1 : 0;
        return balance;
    }

    public static void main(String[] semicolonised) {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        int tt = fs.nextInt();
        for (int ii = 1; ii <= tt; ii++) {
            int n = fs.nextInt();
            for (int i = 1; i <= n; i++) adj.getOrDefault(i, new ArrayList<>()).clear();
            answer = 0;

            for (int i = 2; i <= n; i++) {
                int j = fs.nextInt();
                adj.computeIfAbsent(j, f -> new ArrayList<>()).add(i);
            }

            colour = fs.next();
            getBalanced(1, 1);
            System.out.println(answer);
        }
        out.close();
    }

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}
```

</details>