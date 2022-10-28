class Solution {
public:
	int NthTerm (int n, int mod = 1e9 + 7) {
		long ans = 1;
		for (int i = 1; i <= n; i++) {
			ans = ((ans * i) % mod + 1) % mod;
		}

		return int(ans);
	}

};