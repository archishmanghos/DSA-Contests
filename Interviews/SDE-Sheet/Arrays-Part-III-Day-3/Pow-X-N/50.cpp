double myPow(double x, int n) {
    double ans = 1.0;
    long long n1 = abs(n);
    while (n1 > 0) {
        if (n1 & 1) {
            ans *= x;
            n1 -= 1;
        } else {
            x *= x;
            n1 >>= 1;
        }
    }

    if (n < 0) {
        ans = (double) 1 / ans;
    }

    return ans;
}