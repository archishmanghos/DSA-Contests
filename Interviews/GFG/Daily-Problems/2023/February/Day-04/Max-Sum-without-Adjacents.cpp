#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findMaxSum(int *arr, int n) {
		int cache[n + 2] = {0};
		for (int i = n - 1; i >= 0; i--) cache[i] = max (cache[i + 1], cache[i + 2] + arr[i]);
		return cache[0];
	}
};