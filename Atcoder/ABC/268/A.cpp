#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int A;
	set<int> s;
	for (int i = 1; i <= 5; i++) {
		cin >> A;
		s.insert(A);
	}

	cout << s.size();
	return 0;
}