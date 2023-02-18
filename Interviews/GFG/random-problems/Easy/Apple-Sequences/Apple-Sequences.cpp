#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int appleSequences(int n, int m, string arr) {
		int answer = -1, low = 0, high = n;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			auto F = [&]() -> bool {
				int o = 0;
				for (int i = 0; i < mid - 1; i++) {
					o += arr[i] == 'O';
				}

				for (int i = mid - 1; i < n; i++) {
					o += arr[i] == 'O';
					if (o <= m) return true;
					o -= arr[i - mid + 1] == 'O';
				}

				return false;
			};

			if (F()) {
				answer = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}

		return answer;
	}
};