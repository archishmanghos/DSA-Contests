#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minIteration(int N, int M, int x, int y) {
		int topLeft = x + y - 2;
		int bottomLeft = (N - x) + y - 1;
		int topRight = x + (M - y) - 1;
		int bottomRight = (N - x) + (M - y);
		return max (topLeft, max (bottomLeft, max (topRight, bottomRight)));
	}
};