int countOperations(int num1, int num2) {
    int ans = 0;
    while (num1 > 0 and num2 > 0) {
        if (num1 == num2) {
            return ans + 1;
        }
        int diff = abs(num1 - num2);
        if (num1 >= num2) {
            int times = (diff + num2 - 1) / num2;
            num1 -= times * num2;
            ans += times;
        } else {
            int times = (diff + num1 - 1) / num1;
            num2 -= times * num1;
            ans += times;
        }
        cout << num1 << ' ' << num2 << '\n';
    }
    return ans;
}