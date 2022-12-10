#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int totalEnergy(int initialEnergy, int rate, int timeN) {
	int answer = (initialEnergy * timeN) + (rate * (timeN * (timeN - 1) / 2));
	return answer;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c; cin >> a >> b >> c;
	cout << totalEnergy(a, b, c);
	return 0;
}