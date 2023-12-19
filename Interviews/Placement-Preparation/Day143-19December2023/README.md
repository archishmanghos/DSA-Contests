<h2>661. Image Smoother</h2>

[Link to Problem](https://leetcode.com/problems/image-smoother)

<details><summary>Code</summary>

```java
public class LC661 {
    public int[][] imageSmoother(int[][] img) {
        int n = img.length, m = img[0].length;
        int[][] prefSum = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefSum[i][j] = img[i][j]
                                + (i - 1 >= 0 ? prefSum[i - 1][j] : 0)
                                + (j - 1 >= 0 ? prefSum[i][j - 1] : 0)
                                - (i - 1 >= 0 && j - 1 >= 0 ? prefSum[i - 1][j - 1] : 0);
            }
        }

        int[][] answer = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int corner1_x = Math.min(i + 1, n - 1);
                int corner1_y = Math.min(j + 1, m - 1);
                int corner2_x = Math.max(i - 1, 0);
                int corner2_y = Math.max(j - 1, 0);

                int length = corner1_x - corner2_x + 1;
                int breadth = corner1_y - corner2_y + 1;
                int squares = length * breadth;

                int totalSum = prefSum[corner1_x][corner1_y]
                               - (corner2_x - 1 >= 0 ? prefSum[corner2_x - 1][corner1_y] : 0)
                               - (corner2_y - 1 >= 0 ? prefSum[corner1_x][corner2_y - 1] : 0)
                               + (corner2_x - 1 >= 0 && corner2_y - 1 >= 0 ? prefSum[corner2_x - 1][corner2_y - 1] : 0);
                answer[i][j] = totalSum / squares;
            }
        }

        return answer;
    }
}
```

</details>