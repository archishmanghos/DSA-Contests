#include <bits/stdc++.h>
using namespace std;

void solution(int N) {
	int enable_print = N % 10;
	while (N > 0) {
		if (enable_print == 0 && N % 10 != 0) {
			enable_print = 1;
		}
		else if (enable_print > 0) {
			cout << N % 10;
		}
		N = N / 10;
		if (!enable_print) enable_print = N % 10;
	}
}

int main() {
	int N; cin >> N;
	solution(N);
}