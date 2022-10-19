class Solution {
public:
    int commonFactors(int a, int b) {
        int gcdd = __gcd(a, b), ans = 0;
        for (int i = 1; i * i <= gcdd; i++) {
            if (gcdd % i == 0) {
                if (gcdd / i != i) ans += 2;
                else ans += 1;
            }
        }

        return ans;
    }
};