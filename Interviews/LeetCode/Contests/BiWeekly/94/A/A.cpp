#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int captureForts(vector<int>& forts) {
		int ans = 0;
		for (int i = 0; i < forts.size(); i++) {
			if (forts[i] == 1) {
				int move = 0;
				bool ok = false;
				for (int j = i - 1; j >= 0; j--) {
					if (forts[j] == -1 or forts[j] == 1) {
						ok |= forts[j] == -1;
						break;
					}
					move += 1;
				}
				if (ok) ans = max(ans, move);
				move = 0, ok = false;
				for (int j = i + 1; j < forts.size(); j++) {
					if (forts[j] == -1 or forts[j] == 1) {
						ok |= forts[j] == -1;
						break;
					}
					move += 1;
				}
				if (ok) ans = max(ans, move);
			}
		}

		return ans;
	}
};