class Solution {
    int dp(int idx_s1, int idx_s2, int idx_s3, String s1, String s2, String s3, int[][][] cache) {
        boolean check = idx_s1 == s1.length() && idx_s2 == s2.length();
        if (idx_s3 == s3.length()) return (check ? 1 : 0);
        if (check) return 0;
        if (cache[idx_s1][idx_s2][idx_s3] != -1) return cache[idx_s1][idx_s2][idx_s3];

        int answer = 0;
        if (idx_s1 < s1.length() && s1.charAt(idx_s1) == s3.charAt(idx_s3))
            answer |= dp(idx_s1 + 1, idx_s2, idx_s3 + 1, s1, s2, s3, cache);
        if (idx_s2 < s2.length() && s2.charAt(idx_s2) == s3.charAt(idx_s3))
            answer |= dp(idx_s1, idx_s2 + 1, idx_s3 + 1, s1, s2, s3, cache);

        return cache[idx_s1][idx_s2][idx_s3] = answer;
    }

    public boolean isInterleave(String s1, String s2, String s3) {
        int n_s1 = s1.length(), n_s2 = s2.length(), n_s3 = s3.length();
        int[][][] cache = new int[n_s1 + 1][n_s2 + 1][n_s3];
        for (int[][] i : cache) {
            for (int[] j : i) {
                Arrays.fill(j, -1);
            }
        }

        int answer = dp(0, 0, 0, s1, s2, s3, cache);
        return answer == 1;
    }
}