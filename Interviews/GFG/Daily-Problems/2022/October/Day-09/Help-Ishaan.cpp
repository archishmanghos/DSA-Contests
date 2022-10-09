class Solution {
public:
	bool isPrime(int N) {
		if (N <= 1) return false;
		for (int i = 2; i * i <= N; i++) {
			if (N % i == 0) return false;
		}

		return true;
	}
	int NthTerm(int N) {
		for (int i = 0; ; i++) {
			if (isPrime(N + i) or isPrime(N - i)) {
				return i;
			}
		}

		return -1;
	}
};