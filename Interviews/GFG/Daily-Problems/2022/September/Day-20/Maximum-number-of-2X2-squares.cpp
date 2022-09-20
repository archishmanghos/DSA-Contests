long long int numberOfSquares(long long int base) {
        long long int x = base / 2;
        long long int ans = x * (x - 1) / 2;
        return ans;
}