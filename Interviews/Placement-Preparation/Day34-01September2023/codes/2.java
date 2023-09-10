import java.util.*;

public class LC1326 {
    static class Pair implements Comparable<Pair> {
        private final int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair o) {
            return this.first - o.first;
        }
    }

    private int dp(int idx, List<Pair> range, int n, int[] cache) {
        if (range.get(idx).second == n) return 1;
        if (cache[idx] != -1) return cache[idx];

        int answer = (int) 1e9;
        for (int i = idx + 1; i < range.size(); i++) {
            if (range.get(idx).second < range.get(i).first) break;
            answer = Math.min(answer, dp(i, range, n, cache) + 1);
        }

        return cache[idx] = answer;
    }

    public int minTaps(int n, int[] ranges) {
        List<Pair> range = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            int left_range = Math.max(0, i - ranges[i]);
            int right_range = Math.min(n, i + ranges[i]);
            range.add(new Pair(left_range, right_range));
        }
        Collections.sort(range);

        int[] cache = new int[n + 1];
        Arrays.fill(cache, -1);
        int answer = (int) 1e9;
        for (int i = 0; i < range.size(); i++) {
            if (range.get(i).first == 0) {
                Arrays.fill(cache, -1);
                answer = Math.min(answer, dp(i, range, n, cache));
            }
        }

        return (answer == (int) 1e9 ? -1 : answer);
    }
}