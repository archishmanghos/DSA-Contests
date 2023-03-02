#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int compress(vector<char>& chars) {
		if (chars.back() != 'z') chars.push_back('z');
		else chars.push_back('a');
		int lastAltered = 0, count = 1;
		for (int i = 1; i < chars.size(); i++) {
			if (chars[i] == chars[i - 1]) count += 1;
			else {
				chars[lastAltered++] = chars[i - 1];
				if (count > 1) {
					string x = "";
					while (count) {
						x += ((count % 10) + '0');
						count /= 10;
					}

					while (x.size()) {
						chars[lastAltered++] = x.back();
						x.pop_back();
					}
				}

				count = 1;
			}
		}

		while (chars.size() > lastAltered) chars.pop_back();
		return lastAltered;
	}
};