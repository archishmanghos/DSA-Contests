#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	string A, B, C; cin >> A >> B >> C;
	int cnt[26] = {0}, check = 1;
	for (char c : A) cnt[c - 'A']++;
	for (char c : B) cnt[c - 'A']++;
	for (char c : C) cnt[c - 'A']--;
	for (int i = 0; i < 26; i++) check &= cnt[i] == 0;
	cout << (check ? "YES" : "NO");
	return 0;
}