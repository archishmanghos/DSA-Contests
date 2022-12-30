#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numberOfBeams(vector<string>& bank) {
		int lasers = 0, prevDevices = 0;
		for (int i = 0; i < bank.size(); i++) {
			int devices = 0;
			for (int j = 0; j < bank[0].size(); j++) {
				devices += bank[i][j] == '1';
			}

			if (devices) {
				lasers += devices * prevDevices;
				prevDevices = devices;
			}
		}

		return lasers;
	}
};