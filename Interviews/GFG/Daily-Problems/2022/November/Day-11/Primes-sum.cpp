class Solution {
   public:
    bool isPrime(int N) {
        for (int i = 2; i * i <= N; i++) {
            if (N % i == 0)
                return false;
        }
        return true;
    }
    string isSumOfTwo(int N) {
        for (int i = 2; i <= N - 2; i++) {
            if (isPrime(i) and isPrime(N - i)) {
                return "Yes";
            }
        }

        return "No";
    }
};