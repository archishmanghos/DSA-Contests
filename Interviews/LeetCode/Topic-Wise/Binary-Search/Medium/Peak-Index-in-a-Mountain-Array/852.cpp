#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int peakIndexInMountainArray(vector<int>& arr) {
		int low = 1, high = arr.size() - 2;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1]) return mid;
			if (arr[mid] > arr[mid - 1]) low = mid + 1;
			else high = mid - 1;
		}

		return -1;
	}
};