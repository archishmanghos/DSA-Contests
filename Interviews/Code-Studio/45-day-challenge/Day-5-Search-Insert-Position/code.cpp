#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& arr, int m) {
	auto lb = [&](int val) {
		int answer = -1, low = 0, high = arr.size() - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (arr[mid] >= val) {
				answer = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return (answer == -1 ? arr.size() : answer);
	};

	return lb(m);
}