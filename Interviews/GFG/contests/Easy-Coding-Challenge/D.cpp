int completeRows(int n) {
        int ans = 0;
        for (int i = 1; i * i <= 2 * n; i++) {
                if (i * (i + 1) <= 2 * n) ans = i;
        }

        return ans;
}