public class LC519 {
    int start, n, m;
    public LC519(int m, int n) {
        start = 0;
        this.n = m;
        this.m = n;
    }

    public int[] flip() {
        int[] ans = {start / m, start % m};
        start = (start + 1) % (n * m);
        return ans;
    }

    public void reset() {
    }
}