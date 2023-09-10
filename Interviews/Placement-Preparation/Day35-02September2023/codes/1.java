import java.util.Arrays;

public class LC2707 {
    private int dp (int idx, String s, String[] dictionary, int[] cache) {
        if (idx == s.length()) return 0;
        if (cache[idx] != -1) return cache[idx];

        int answer = dp(idx + 1, s, dictionary, cache) + 1;
        for (String word : dictionary) {
            if (idx + word.length() <= s.length()) {
                if (s.startsWith(word, idx)) {
                    answer = Math.min(answer, dp (idx + word.length(), s, dictionary, cache));
                }
            }
        }

        return cache[idx] = answer;
    }
    public int minExtraChar(String s, String[] dictionary) {
        int[] cache = new int[s.length()];
        Arrays.fill(cache, -1);
        return dp(0, s, dictionary, cache);
    }
}