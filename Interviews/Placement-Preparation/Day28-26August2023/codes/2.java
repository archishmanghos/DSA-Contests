import java.util.Arrays;
import java.util.Comparator;

public class LC646 {
    int dp(int idx, int lastIdx, int[][] pairs, int[][] cache) {
        if (idx == pairs.length) return 0;
        if (cache[idx][lastIdx] != -1) return cache[idx][lastIdx];

        int answer = dp(idx + 1, lastIdx, pairs, cache);
        if (lastIdx == 0 || pairs[lastIdx - 1][1] < pairs[idx][0])
            answer = Math.max(answer, dp(idx + 1, idx + 1, pairs, cache) + 1);

        return cache[idx][lastIdx] = answer;
    }

    public int findLongestChain(int[][] pairs) {
        int n = pairs.length;
        Arrays.sort(pairs, Comparator.comparingInt(a -> a[0]));
        int[][] cache = new int[n][n + 1];
        for (int[] i : cache) Arrays.fill(i, -1);
        return dp(0, 0, pairs, cache);
    }
}
