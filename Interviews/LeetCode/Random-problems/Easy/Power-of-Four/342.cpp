bool isPowerOfFour(int n) {
        double c = log2(n) / 2.0;
        return (n > 0 and (double)c == (int)c);
}