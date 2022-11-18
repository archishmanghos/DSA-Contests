class Solution {
public:
    bool isUgly(int n) {
        int primes[3] = {2, 3, 5};
        for (int i = 0; i < 3; i++) {
            while (n > 1 and n % primes[i] == 0) {
                n /= primes[i];
            }
        }
        
        return n == 1;
    }
};