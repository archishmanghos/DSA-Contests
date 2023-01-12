#include <bits/stdc++.h>
using namespace std;

bool solution(string &S) {
	bool bStarts = false;
	for (char c : S) {
		if (c == 'b') bStarts = true;
		if (c == 'a' and bStarts) return false;
	}

	return true;
}