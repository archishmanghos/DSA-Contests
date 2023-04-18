#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int A, B, C, D; cin >> A >> B >> C >> D;
	int Misha = max((3 * A) / 10, A - (A * C / 250));
	int Vasya = max((3 * B) / 10, B - (B * D / 250));

	cout << (Misha > Vasya ? "Misha" : Misha < Vasya ? "Vasya" : "Tie");
	return 0;
}