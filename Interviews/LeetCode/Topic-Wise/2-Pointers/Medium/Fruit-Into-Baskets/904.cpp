#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int totalFruit(vector<int>& fruits) {
		int answer = 0;
		unordered_map<int, int> fruitCnt;
		for (int i = 0, j = 0; i < fruits.size(); i++) {
			while (j < fruits.size() and fruitCnt.size() < 2) fruitCnt[fruits[j++]] += 1;
			while (j < fruits.size() and fruitCnt.find(fruits[j]) != fruitCnt.end()) fruitCnt[fruits[j++]] += 1;

			answer = max (answer, j - i);
			fruitCnt[fruits[i]] -= 1;
			if (!fruitCnt[fruits[i]]) fruitCnt.erase(fruits[i]);
		}

		return answer;
	}
};