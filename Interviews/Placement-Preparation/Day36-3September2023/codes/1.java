import java.util.Arrays;

public class LC62 {
    private int dp(int i, int j, int n, int m, int[][] cache) {
        if (i == n - 1 && j == m - 1) return 1;
        if (i == n || j == m) return 0;
        if (cache[i][j] != -1) return cache[i][j];

        int answer = 0;
        answer += dp(i + 1, j, n, m, cache) + dp(i, j + 1, n, m, cache);
        return cache[i][j] = answer;
    }

    public int uniquePaths(int m, int n) {
        int[][] cache = new int[m][n];
        for (int[] arr : cache) Arrays.fill(arr, -1);
        return dp(0, 0, m, n, cache);
    }
}