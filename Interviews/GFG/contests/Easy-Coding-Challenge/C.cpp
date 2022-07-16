int convertNum(int n) {
        int ans = 0;
        while (n > 0) {
                ans += (n % 10) * (n % 10);
                n /= 10;
        }
        return ans;
}
bool beautifulNumber(int n) {
        while (n != 1 and n != 89) {
                n = convertNum(n);
        }
        return n == 1;
}