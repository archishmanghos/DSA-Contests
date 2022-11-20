class Solution {
  public:
    long long lcmTriplets(long long N) {
        if (N % 6 == 0) {
            return (N - 1) * (N - 2) * (N - 3); 
        }
        if (N <= 2) {
            return N;
        }
        long long ans = N * (N - 1);
        for (long long i = N - 2, j = 2; i >= 1 and j < 3; i--) {
            if (__gcd(ans, i) == 1) {
                ans *= i;
                j += 1;
            }
        }
        
        return ans;
    }
};