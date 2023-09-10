public class LC1359 {
    public int countOrders(int n) {
        long answer = 1, mod = (int) 1e9 + 7;
        for (int i = 1; i <= 2 * n; i++) {
            if (i % 2 == 0) answer = (answer * (i / 2)) % mod;
            else answer = (answer * i) % mod;
        }

        return (int) answer;
    }
}