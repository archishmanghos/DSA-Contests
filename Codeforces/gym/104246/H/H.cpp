#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int K; cin >> K;
	switch (K) {
	case 1: cout << "Alas! Farha is bitten by snake. She is now at 75.";
		break;
	case 2: cout << "Nothing happened to her.";
		break;
	case 3: cout << "Nothing happened to her.";
		break;
	case 4: cout << "Alas! Farha is bitten by snake. She is now at 79.";
		break;
	case 5: cout << "Farha is on ladder.";
		break;
	default: cout << "Yay! Farha has won the game. She is now at 100.";
	}
	return 0;
}