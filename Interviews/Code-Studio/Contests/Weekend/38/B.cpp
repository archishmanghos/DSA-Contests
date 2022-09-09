#include <bits/stdc++.h>

string CycMin(int n, string s) {
	int pos1 = -1, pos2 = n;
	for (int i = 0; i < n; i++) {
		if (s[i] != 'a') {
			pos1 = i;
			break;
		}
	}

	for (int i = pos1 + 1; i < n; i++) {
		if (s[i] == 'a') {
			pos2 = i;
			break;
		}
	}

	if (pos1 == -1) {
		s[n - 1] = 'z';
		return s;
	}
	for (int i = pos1; i < pos2; i++) {
		s[i] = (s[i] - 1);
	}

	return s;
}