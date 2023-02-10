#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxInstance(string s) {
		int a = 0, b = 0, l = 0, o = 0, n = 0;
		for (char c : s) {
			a += c == 'a';
			b += c == 'b';
			l += c == 'l';
			o += c == 'o';
			n += c == 'n';
		}

		l >>= 1;
		o >>= 1;
		return min(a, min(b, min (l, min(o, n))));
	}
};