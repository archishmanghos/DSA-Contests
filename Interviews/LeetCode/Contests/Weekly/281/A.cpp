int countEven(int num) {
    int ans = 0;
    for (int i = 1; i <= num; i++) {
        int sum = 0, j = i;
        while (j > 0) {
            sum += j % 10;
            j /= 10;
        }
        ans += sum % 2 == 0;
    }
    return ans;
}