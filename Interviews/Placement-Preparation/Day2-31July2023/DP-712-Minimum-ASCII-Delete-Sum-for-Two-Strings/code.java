import java.util.Arrays;

class LC712 {
    private int[][] cache;
    private int dp(int idx1, int idx2, String s1, String s2) {
        if (idx1 < 0) {
            int moreDel = 0;
            while (idx2 >= 0) moreDel += s2.charAt(idx2--);
            return moreDel;
        }
        if (idx2 < 0) {
            int moreDel = 0;
            while (idx1 >= 0) moreDel += s1.charAt(idx1--);
            return moreDel;
        }
        if (cache[idx1][idx2] != -1) return cache[idx1][idx2];

        int answer = 1000000;
        if (s1.charAt(idx1) == s2.charAt(idx2)) answer = dp (idx1 - 1, idx2 - 1, s1, s2);
        else {
            answer = dp (idx1 - 1, idx2, s1, s2) + (int)s1.charAt(idx1);
            answer = Math.min (answer, dp (idx1, idx2 - 1, s1, s2) + (int)s2.charAt(idx2));
        }

        return cache[idx1][idx2] = answer;
    }
    public int minimumDeleteSum(String s1, String s2) {
        cache = new int[1005][1005];
        for (int i = 0; i <= 1000; i++) Arrays.fill(cache[i], -1);

        return dp (s1.length() - 1, s2.length() - 1, s1, s2);
    }
}