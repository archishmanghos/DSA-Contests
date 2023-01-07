#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string categorizeBox(int length, int width, int height, int mass) {
		int64_t volume = 1LL * length * width * height;
		bool bulky = false, heavy = false;
		if (length >= 10000 or width >= 10000 or height >= 10000 or volume >= 1000000000) bulky = true;
		if (mass >= 100) heavy = true;

		if (bulky and heavy) return "Both";
		if (bulky) return "Bulky";
		if (heavy) return "Heavy";
		return "Neither";
	}
};